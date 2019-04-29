#include <menu/menu_handler.hpp>

MenuHandler::MenuHandler()
  : menu_display_{100, 10, 30, 16}
  , selected_index_{}
{
}

GameStatus MenuHandler::operator()(GameMaster& master)
{
  Menu        menu{};
  KeyManager  keyboard{};

  while (true)
  {
    menu_display_.show(menu, selected_index_);
    keyboard.update();
    switch (keyboard.get())
    {
      case KeyManager::Up:
        if (selected_index_ > 0)
          --selected_index_;
        break;
      case KeyManager::Down:
        ++selected_index_;
        break;
      case KeyManager::Space:
      case KeyManager::Back:
        menu_display_.hide();
        return GameStatus{Mode::Dungeon, Task::Show};
      case KeyManager::Enter:
        auto content{menu.get_content()};
        auto itr{std::next(content.begin(), selected_index_)};
        return itr->second();
    }
  }
  menu_display_.hide();

  return GameStatus{};
}
