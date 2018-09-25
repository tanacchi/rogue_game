#include <character/character.hpp>

namespace character
{
  Character::Character(map::Point point)
    : point_{point}
  {
  }

  map::Point Character::get_point() const
  {
    return point_;
  }
}
