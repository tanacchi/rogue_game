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
  int input{getch()};
  mvprintw(21, 15, "Input char: [%c]\n", (char)input);
  return static_cast<KeyState>(input);
}

std::string key_to_str(KeyboardManager::KeyState key)
{
  switch (key) {
  case KeyboardManager::KeyState::Space:
    return "Space";
  case KeyboardManager::KeyState::Enter:
    return "Enter";
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
    mvprintw(21, 15, "Input char: [%s]\n", key_to_str(key).data());
  }
  return 0;
}