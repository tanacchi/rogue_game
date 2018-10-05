#include <map>

#include <keyboard/keyboard_manager.hpp>


const KeyboardManager::KeyState KeyboardManager::get_key() noexcept
{
  static const std::map<int, KeyboardManager::KeyState> key_state_table = {
    {32,            KeyState::Space},
    {10,            KeyState::Enter},
    {KEY_BACKSPACE, KeyState::Back},
    {KEY_UP,        KeyState::Up},
    {KEY_DOWN,      KeyState::Down},
    {KEY_RIGHT,     KeyState::Right},
    {KEY_LEFT,      KeyState::Left}
  };
  const std::map<int, KeyboardManager::KeyState>::const_iterator key_state_itr{key_state_table.find(getch())};
  return (key_state_itr != key_state_table.end()) ? key_state_itr->second : KeyState::Unknown;
}
