#include <character/character.hpp>

Character::Character(std::size_t x, std::size_t y)
  : x_{x}, y_{y}
{
}

std::size_t Character::get_x()
{
  return x_;
}

std::size_t Character::get_y()
{
  return y_;
}

