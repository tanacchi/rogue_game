#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>
#include <cstdint>

class KeyboardManager
{
public:
  enum class KeyState : std::uint16_t
  {
    Space   = 32,
    Enter   = 10,
    Back    = KEY_BACKSPACE,
    Up      = KEY_UP,
    Down    = KEY_DOWN,
    Right   = KEY_RIGHT,
    Left    = KEY_LEFT,
    Unknown = 0
  };

  static const KeyState get_key() noexcept;
};

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
