#ifndef INCLUDED_KEY_MANAGER_HPP
#define INCLUDED_KEY_MANAGER_HPP

#include <ncurses.h>
#include <cstdint>
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

    explicit KeyManager(KeyManager::KeyType key = KeyManager::Null) noexcept;
    
    explicit operator KeyManager::KeyType() const noexcept;
    explicit operator bool() const noexcept;
    bool operator==(const KeyManager& rhs) const noexcept;
    bool operator==(KeyManager::KeyType&& rhs) const noexcept;
    friend KeyManager operator|(const KeyManager& lhs, const KeyManager& rhs);
    KeyManager operator|(KeyManager::KeyType&& rhs);

    void update() noexcept;
    KeyManager::KeyType get() const noexcept;
  private:
    KeyManager::KeyType key_;
};

#endif  // INCLUDED_KEY_MANAGER_HPP
