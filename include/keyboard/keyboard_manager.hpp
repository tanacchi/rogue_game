#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>

class KeyboardManager
{
public:
  enum class KeyState
  {
    Space   = 32,
    Enter   = 10,
    Back    = KEY_BACKSPACE,
    Up      = KEY_UP,
    Down    = KEY_DOWN,
    Right   = KEY_RIGHT,
    Left    = KEY_LEFT,
    Unknown = -1
  };

  static const KeyState get_key() noexcept;
};

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
