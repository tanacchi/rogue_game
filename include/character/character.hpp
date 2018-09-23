#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <cstddef>
#include <memory>

#include <keyboard/keyboard_manager.hpp>

class Character
{
public:
  Character(std::size_t x, std::size_t y, std::unique_ptr<KeyboardManager>&& km_ptr=nullptr);
  std::size_t get_x() const;
  std::size_t get_y() const;
private:
  std::size_t x_;
  std::size_t y_;
  std::unique_ptr<KeyboardManager> km_ptr_;
};

#endif  // INCLUDED_CHARACTER_HPP
