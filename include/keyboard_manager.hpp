#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>

class KeyboardManager
{
public:
  enum KeyState
  {
    Space   = 32,
    Up      = KEY_UP,
    Down    = KEY_DOWN,
    Right   = KEY_RIGHT,
    Left    = KEY_LEFT,
    Unknown =-1
  };

  KeyboardManager();
  ~KeyboardManager();
  KeyState get_key();
};

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
