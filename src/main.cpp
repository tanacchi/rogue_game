#include <iostream>

#include <keyboard_manager.hpp>
#include <display_panel.hpp>
#include <map_display.hpp>

std::string key_to_str(KeyboardManager::KeyState key)
{
  switch (key) {
  case KeyboardManager::KeyState::Space:
    return "Space";
  case KeyboardManager::KeyState::Enter:
    return "Enter";
  case KeyboardManager::KeyState::Back:
    return "Back";
  case KeyboardManager::KeyState::Up:
    return "Up";
  case KeyboardManager::KeyState::Down:
    return "Down";
  case KeyboardManager::KeyState::Right:
    return "Right";
  case KeyboardManager::KeyState::Left:
    return "Left";
  default:
    return "Unknown";
  }
}

int main()
{
  DisplayPanel    dp{10, 10, 10, 5};
  KeyboardManager km{};
  border(0, 0, 0, 0, 0, 0, 0, 0);
  noecho();
  curs_set(0);
  std::cout << "Hello, rouge_game." << std::endl;
  while (true) {
    dp.draw_outline();
    KeyboardManager::KeyState key{km.get_key()};
    mvprintw(22, 15, "Input KeyState: [%s]\n", key_to_str(key).data());
  }

  return 0;
}
