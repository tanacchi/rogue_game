#include <keyboard_manager.hpp>

KeyboardManager::KeyState KeyboardManager::get_key() const noexcept
{
  return static_cast<KeyState>(getch());
}
