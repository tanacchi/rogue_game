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
