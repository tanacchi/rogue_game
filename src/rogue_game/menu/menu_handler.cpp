#include <functional>
#include <utility>

#include <menu/menu_handler.hpp>
#include <game_master/game_master.hpp>

MenuHandler::MenuHandler()
  : menu_ptr{}
  , menu_display_{100, 10, 30, 16}
  , selected_index_{}
{
}

GameStatus MenuHandler::operator()(GameMaster& master)
{
  KeyManager keyboard{};
  GameStatus next_status{};
  set_item_content(master);
  menu_ptr.reset(new Menu{Menu::base_content});

  while (menu_ptr)
  {
#ifndef DEBUG
    menu_display_.show(*menu_ptr, selected_index_);
#endif
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
        next_status = itr->second(menu_ptr);
        selected_index_ = 0;
        break;
    }
  }
  menu_display_.hide();
  return next_status;
}

void MenuHandler::set_item_content(GameMaster& master)
{
  Menu::item_content.clear();
  auto names{master.player.get_item_name_array()};
  for (auto name : names)
  {
    auto action{
      [&](Menu::MenuPtr& menu_ptr){
        menu_ptr.release();
        master.player.add_money(100);
        master.player.dispose_item(selected_index_);
        return GameStatus{};
      }
    };
    using namespace std::placeholders;
    Menu::ContentType::value_type elem{std::make_pair(name, std::bind(action, _1))};
    Menu::item_content.insert(elem);
  }
}
