#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <cstddef>

class Character
{
public:
  Character(std::size_t x, std::size_t y);
  std::size_t get_x();
  std::size_t get_y();
private:
  std::size_t x_;
  std::size_t y_;
};

#endif  // INCLUDED_CHARACTER_HPP
