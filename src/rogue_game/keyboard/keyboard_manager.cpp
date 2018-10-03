#include <keyboard/keyboard_manager.hpp>

const KeyboardManager::KeyState KeyboardManager::get_key() noexcept
{
  return static_cast<KeyState>(getch());
}
