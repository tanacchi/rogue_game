#include <menu/menu_handler.hpp>

MenuHandler::MenuHandler()
  : menu_ptr{}
  , menu_display_{100, 10, 30, 16}
  , selected_index_{}
{
}

GameStatus MenuHandler::operator()(GameMaster& master)
{
  return handle(Menu::base_content);
}

GameStatus MenuHandler::handle(const Menu::ContentType& content)
{
  KeyManager keyboard{};
  GameStatus next_status{};
  menu_ptr.reset(new Menu{content});

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
        next_status =  GameStatus{Mode::Dungeon, Task::Show};
        menu_ptr.release();
        break;
      case KeyManager::Enter:
        auto content{menu_ptr->get_content()};
        auto itr{std::next(content.begin(), selected_index_)};
        next_status = itr->second();
        menu_ptr.release();
        break;
    }
  }
  menu_display_.hide();
  return next_status;
}
