#include <iostream>
#include <keyboard_manager.hpp>
#include <string>

KeyboardManager::KeyboardManager()
{
  initscr();
  keypad(stdscr, TRUE);
}

KeyboardManager::~KeyboardManager()
{
  endwin();
}

KeyboardManager::KeyState KeyboardManager::get_key()
{
  static int count{0};
  int input{getch()};
  if (input != static_cast<int>(KeyboardManager::KeyState::Unknown)) count++;
  mvprintw(20, 15, "Count: [%d]\n", count);
  mvprintw(21, 15, "Input char: [%c]\n", (char)input);
  // return static_cast<KeyState>(input);  // FIX: Unknown のフィルターが機能していない
  switch (static_cast<KeyState>(input)) {                //  Refactor Required
  case KeyState::Space: return KeyState::Space;
  case KeyState::Enter: return KeyState::Enter;
  case KeyState::Back:  return KeyState::Back;
  case KeyState::Up:    return KeyState::Up;
  case KeyState::Down:  return KeyState::Down;
  case KeyState::Right: return KeyState::Right;
  case KeyState::Left:  return KeyState::Left;
  default:              return KeyState::Unknown;
  }
}

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
  case KeyboardManager::KeyState::Unknown:
    return "Unknown";
  default:
    return "???????";
  }
}

int main()
{
  KeyboardManager km{};
  std::cout << "Hello, rouge_game." << std::endl;
  while (true) {
    KeyboardManager::KeyState key{km.get_key()};
    mvprintw(22, 15, "Input KeyState: [%s]\n", key_to_str(key).data());
  }
  return 0;
}
