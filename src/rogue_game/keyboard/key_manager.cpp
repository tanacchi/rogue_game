#include <keyboard/key_manager.hpp>

const KeyManager::KeyType KeyManager::Space;
const KeyManager::KeyType KeyManager::Enter;
const KeyManager::KeyType KeyManager::Back;
const KeyManager::KeyType KeyManager::Up;
const KeyManager::KeyType KeyManager::Down;
const KeyManager::KeyType KeyManager::Right;
const KeyManager::KeyType KeyManager::Left;
const KeyManager::KeyType KeyManager::Null;
const KeyManager::KeyType KeyManager::Enable;
const KeyManager::KeyType KeyManager::Arrow;

KeyManager::KeyType KeyManager::current_key_ {KeyManager::Null};
KeyManager::KeyType KeyManager::previous_key_{KeyManager::Null};

const std::unordered_map<int, KeyManager::KeyType> KeyManager::key_state_table{{
  {32,            KeyManager::Space},
  {10,            KeyManager::Enter},
  {KEY_BACKSPACE, KeyManager::Back },
  {KEY_UP,        KeyManager::Up   },
  {KEY_DOWN,      KeyManager::Down },
  {KEY_RIGHT,     KeyManager::Right},
  {KEY_LEFT,      KeyManager::Left },
}};

bool KeyManager::is_null()
{
  return get() != KeyManager::Null;
}

void KeyManager::update()
{
  previous_key_ = current_key_;
  const auto& itr{key_state_table.find(getch())};
  current_key_ = (itr == key_state_table.end()) ? KeyManager::Null : itr->second;
}

bool KeyManager::is_match(KeyManager::KeyType condition)
{
  return (get() & condition) != KeyManager::KeyType{};
}

KeyManager::KeyType KeyManager::get()
{
  return current_key_ != previous_key_ ? current_key_ : KeyManager::Null;;
}
