#include <map>

#include <keyboard/keyboard_manager.hpp>


const KeyboardManager::KeyState KeyboardManager::get_key() noexcept
{
  // キーコードと KeyState の対応表
  static const std::map<int, const KeyboardManager::KeyState> key_state_table = {
    {32,            KeyState::Space},
    {10,            KeyState::Enter},
    {KEY_BACKSPACE, KeyState::Back },
    {KEY_UP,        KeyState::Up   },
    {KEY_DOWN,      KeyState::Down },
    {KEY_RIGHT,     KeyState::Right},
    {KEY_LEFT,      KeyState::Left }
  };
  // 上の表に該当しなかったものは KeyState::Unknown と認識する
  const std::map<int, const KeyboardManager::KeyState>::const_iterator key_state_itr{key_state_table.find(getch())};
  return (key_state_itr != key_state_table.end()) ? key_state_itr->second : KeyState::Unknown;
}

std::ostream& operator<<(std::ostream& os, KeyboardManager::KeyState key_state)
{                               // もうマクロで良くないかって思う
  static const std::map<KeyboardManager::KeyState, const std::string> key_string_table = {
    {KeyboardManager::KeyState::Space,   "[KeyState::Space]"  },
    {KeyboardManager::KeyState::Enter,   "[KeyState::Enter]"  },
    {KeyboardManager::KeyState::Back,    "[KeyState::Back]"   },
    {KeyboardManager::KeyState::Up,      "[KeyState::Up]"     },
    {KeyboardManager::KeyState::Down,    "[KeyState::Down]"   },
    {KeyboardManager::KeyState::Right,   "[KeyState::Right]"  },
    {KeyboardManager::KeyState::Left,    "[KeyState::Left]"   },
    {KeyboardManager::KeyState::Unknown, "[KeyState::Unknown]"},
    {KeyboardManager::KeyState::Enable,  "[KeyState::Enable]" },
    {KeyboardManager::KeyState::Arrow,   "[KeyState::Arrow]"  },
  };
  os << key_string_table.at(key_state);
  return os;
}
