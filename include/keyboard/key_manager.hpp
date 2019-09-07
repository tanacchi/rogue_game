#ifndef INCLUDED_KEY_MANAGER_HPP
#define INCLUDED_KEY_MANAGER_HPP

#include <cstdint>
#include <ncurses.h>
#include <unordered_map>

class KeyManager
{
  public:
    using KeyType = std::uint8_t;

    static const KeyType Space  {0b00000001};
    static const KeyType Enter  {0b00000010};
    static const KeyType Back   {0b00000100};
    static const KeyType Up     {0b00001000};
    static const KeyType Down   {0b00010000};
    static const KeyType Right  {0b00100000};
    static const KeyType Left   {0b01000000};
    static const KeyType Null   {0b10000000};
    static const KeyType Enable {0b01111111};
    static const KeyType Arrow  {0b01111000};

    static const std::unordered_map<int, KeyManager::KeyType> key_state_table;

    static bool is_null();
    static void update();
    static bool is_match(KeyType condition);
    static KeyManager::KeyType get();

  private:
    static KeyManager::KeyType current_key_;
    static KeyManager::KeyType previous_key_;
};

#endif  // INCLUDED_KEY_MANAGER_HPP
