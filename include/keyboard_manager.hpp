#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>

class KeyboardManager
{
public:
  enum KeyState
  {
    Space   = 32,
    Up      = 3,
    Down    = 2,
    Right   = 5,
    Left    = 4,
    Unknown =-1
  };

  KeyboardManager();
  ~KeyboardManager();
  KeyState get_key();
};

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
