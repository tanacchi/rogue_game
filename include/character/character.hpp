#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <cstddef>

class Character
{
public:
  Character(std::size_t x, std::size_t y);
private:
  std::size_t x_;
  std::size_t y_;
};

#endif  // INCLUDED_CHARACTER_HPP
