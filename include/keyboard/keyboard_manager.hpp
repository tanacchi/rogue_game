#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>
#include <cstdint>

class KeyboardManager
{
public:
  enum class KeyState : std::uint8_t
  {
    Space   = 0x0001 << 0,
    Enter   = 0x0001 << 1,
    Back    = 0x0001 << 2,
    Up      = 0x0001 << 3,
    Down    = 0x0001 << 4,
    Right   = 0x0001 << 5,
    Left    = 0x0001 << 6,
    Unknown = 0x0001 << 7,
  };

  static const KeyState get_key() noexcept;
};

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
