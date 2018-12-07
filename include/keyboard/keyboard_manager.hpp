#ifndef INCLUDED_KEYBOARD_MANAGER_HPP
#define INCLUDED_KEYBOARD_MANAGER_HPP

#include <ncurses.h>
#include <cstdint>
#include <ostream>

// キーボード入力を扱うクラス
class KeyboardManager
{
public:
  // 使用可能なキーボード入力
  enum class KeyState : std::uint8_t
  {
    Space   = 0x01 << 0,
    Enter   = 0x01 << 1,
    Back    = 0x01 << 2,
    Up      = 0x01 << 3,
    Down    = 0x01 << 4,
    Right   = 0x01 << 5,
    Left    = 0x01 << 6,
    Unknown = 0x01 << 7,
    Enable  = 0xff >> 1,
    Arrow   = Up | Down | Right | Left
  };

  // ncurses のキーコードから KeyState に変換
  static const KeyState get_key() noexcept;
};

std::ostream& operator<<(std::ostream& os, KeyboardManager::KeyState key_state);

#endif  // INCLUDED_KEYBOARD_MANAGER_HPP
