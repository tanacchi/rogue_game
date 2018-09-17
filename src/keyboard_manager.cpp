#include <keyboard_manager.hpp>

KeyboardManager::KeyboardManager()
{
}

KeyboardManager::~KeyboardManager()
{
}

KeyboardManager::KeyState KeyboardManager::get_key() const noexcept
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
