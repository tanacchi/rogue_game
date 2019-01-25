#ifndef INCLUDED_KEY_MANAGER_HPP
#define INCLUDED_KEY_MANAGER_HPP

#include <ncurses.h>
#include <cstdint>
#include <unordered_map>

class KeyManager
{
  public:
    using KeyType = std::uint8_t;

    static const KeyType Space;
    static const KeyType Enter;
    static const KeyType Back;
    static const KeyType Up;
    static const KeyType Down;
    static const KeyType Right;
    static const KeyType Left;
    static const KeyType Null;
    static const KeyType Enable;
    static const KeyType Arrow;

    static const std::unordered_map<int, KeyManager::KeyType> key_state_table;
};

#endif  // INCLUDED_KEY_MANAGER_HPP
