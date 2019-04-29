#include <menu/menu_handler.hpp>
#include <display/menu_display.hpp>

GameStatus MenuHandler::operator()(GameMaster& master)
{
  Menu        menu{};
  MenuDisplay menu_display{100, 10, 30, 16};
  KeyManager  keyboard{};

  while (true)
  {
    menu_display.show(menu, selected_index_);
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
        menu_display.hide();
        return GameStatus{Mode::Dungeon, Task::Show};
    }
  }
  menu_display.hide();

  return GameStatus{};
}
