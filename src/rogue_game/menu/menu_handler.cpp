#include <functional>
#include <utility>

#include <menu/menu_handler.hpp>
#include <character/inventory.hpp>
#include <game_master/game_master.hpp>

#include <action/action_handler.hpp>
#include <action/gold_action.hpp>
#include <action/food_action.hpp>
#include <action/any_action.hpp>

MenuHandler::MenuHandler()
  : menu_ptr{}
  , menu_display_{100, 10, 30, 16}
  , selected_index_{}
{
}

GameStatus MenuHandler::operator()(const std::shared_ptr<GameMaster>& master)
{
  KeyManager keyboard{};
  GameStatus next_status{};
  set_item_content(master);
  menu_ptr.reset(new Menu{Menu::base_content});

  while (menu_ptr)
  {
    menu_display_.show(*menu_ptr, selected_index_);
    keyboard.update();
    switch (keyboard.get())
    {
      case KeyManager::Up:
        if (selected_index_ > 0)
          --selected_index_;
        break;
      case KeyManager::Down:
        if (selected_index_ + 1 < menu_ptr->content_.size())
          ++selected_index_;
        break;
      case KeyManager::Space:
      case KeyManager::Back:
        selected_index_ = 0;
        next_status =  GameStatus{};
        menu_ptr.release();
        break;
      case KeyManager::Enter:
        auto content{menu_ptr->get_content()};
        auto itr{std::next(content.begin(), selected_index_)};
        if (itr != content.end())
        {
          next_status = itr->second(menu_ptr);
          selected_index_ = 0;
        }
        break;
    }
  }
  menu_display_.hide();
  return next_status;
}

void MenuHandler::set_item_content(const std::shared_ptr<GameMaster>& master)
{
  Menu::item_content.clear();

  const auto& items{master->player.inventory_ptr->get_items()};
  auto base_action{
    [&](Menu::MenuPtr& menu_ptr, std::function<void(void)> specific_action){
      specific_action();
      master->player.inventory_ptr->dispose(selected_index_);
      menu_ptr.release();
      return GameStatus{Task::Act};
    }
  };
  std::function<void(void)> specific_action{};

  for (const auto item : items)
  {
    if (item->type == "gold")
    {
      specific_action = 
        [=](){
          const Gold& gold(dynamic_cast<Gold&>(*item));
          ActionHandler::push(GoldAction<ConsumeTag>(gold));
        };
    }
    else if (item->type == "food")
    {
      specific_action = 
        [=](){
          const Food& food(dynamic_cast<Food&>(*item));
          ActionHandler::push(FoodAction<ConsumeTag>(food));
        };
    }
    Menu::item_content.emplace(item->type, std::bind(base_action, std::placeholders::_1, specific_action));
  }
}
