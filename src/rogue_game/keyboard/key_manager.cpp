#include <keyboard/key_manager.hpp>

const KeyManager::KeyType KeyManager::Space  = 0x01 << 0;
const KeyManager::KeyType KeyManager::Enter  = 0x01 << 1;
const KeyManager::KeyType KeyManager::Back   = 0x01 << 2;
const KeyManager::KeyType KeyManager::Up     = 0x01 << 3;
const KeyManager::KeyType KeyManager::Down   = 0x01 << 4;
const KeyManager::KeyType KeyManager::Right  = 0x01 << 5;
const KeyManager::KeyType KeyManager::Left   = 0x01 << 6;
const KeyManager::KeyType KeyManager::Null   = 0x01 << 7;
const KeyManager::KeyType KeyManager::Enable = 0xff >> 1;
const KeyManager::KeyType KeyManager::Arrow  = KeyManager::Up | KeyManager::Down | KeyManager::Right | KeyManager::Left;

const std::unordered_map<int, KeyManager::KeyType> KeyManager::key_state_table{{
  {32,            KeyManager::Space},
  {10,            KeyManager::Enter},
  {KEY_BACKSPACE, KeyManager::Back },
  {KEY_UP,        KeyManager::Up   },
  {KEY_DOWN,      KeyManager::Down },
  {KEY_RIGHT,     KeyManager::Right},
  {KEY_LEFT,      KeyManager::Left },
}};

KeyManager::KeyManager(KeyManager::KeyType key) noexcept
  : key_{key}
{
}

KeyManager::operator KeyManager::KeyType() const noexcept
{
  return key_;
}

KeyManager::operator bool() const noexcept
{
  return key_ != KeyManager::Null;
}

bool KeyManager::operator==(const KeyManager& rhs) const noexcept
{
  return key_ == rhs.key_;
}

bool KeyManager::operator==(KeyManager::KeyType&& rhs) const noexcept
{
  return key_ == rhs;
}

void KeyManager::update() noexcept
{
  auto itr{key_state_table.find(getch())};
  key_ = (itr == key_state_table.end()) ? KeyManager::Null : itr->second;
}

KeyManager::KeyType KeyManager::get() const noexcept
{
  return key_;
}

KeyManager operator|(const KeyManager& lhs, const KeyManager& rhs)
{
  return KeyManager(lhs.key_ | rhs.key_);
}

KeyManager KeyManager::operator|(KeyManager::KeyType&& rhs)
{
  return KeyManager(key_ | rhs);
}

