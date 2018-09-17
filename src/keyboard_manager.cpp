#include <keyboard_manager.hpp>

KeyboardManager::KeyState KeyboardManager::get_key() const noexcept
{
  static int count{0};
  int input{getch()};
  if (input != static_cast<int>(KeyboardManager::KeyState::Unknown)) count++;
  mvprintw(20, 15, "Count: [%d]\n", count);
  mvprintw(21, 15, "Input char: [%c]\n", (char)input);
  return static_cast<KeyState>(input);  // FIX: Unknown のフィルターが機能していない
}
