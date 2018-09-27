#include <character/character.hpp>

namespace character
{
  Character::Character(map::Point position)
    : position_{position}
  {
  }

  map::Point Character::get_position() const
  {
    return position_;
  }
}
