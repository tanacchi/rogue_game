#include <functional>
#include <utility>

#include <menu/menu_handler.hpp>
#include <character/inventory.hpp>
#include <game_master/game_master.hpp>

#include <action/action_handler.hpp>
#include <action/gold_action.hpp>
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
        next_status =  GameStatus{Mode::Dungeon, Task::Show};
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
  auto names{master->player.inventory_ptr->get_item_names()};
  for (auto name : names)
  {
    if (name == "gold")
    {
      auto action{
        [&](Menu::MenuPtr& menu_ptr){  // XXX: So duty.
          menu_ptr.release();
          auto target_item_itr{master->player.inventory_ptr->get_item_by_index(selected_index_)};
          const Gold& gold_ptr(dynamic_cast<Gold&>(*target_item_itr));
          ActionHandler::push_action(GoldAction<ConsumeTag>(gold_ptr));
          master->player.inventory_ptr->dispose(selected_index_);
          return GameStatus{Mode::Dungeon, Task::Act};
        }
      };
      using namespace std::placeholders;
      Menu::item_content.emplace(name, std::bind(action, _1));
    }
    else if (name == "food")
    {
      auto action{
        [&](Menu::MenuPtr& menu_ptr){
          menu_ptr.release();
          master->player.heal(10);
          master->player.inventory_ptr->dispose(selected_index_);
          return GameStatus{Mode::Dungeon, Task::Act};
        }
      };
      using namespace std::placeholders;
      Menu::item_content.emplace(name, std::bind(action, _1));
    }
  }
}
