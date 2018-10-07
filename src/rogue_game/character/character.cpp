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

  void Character::set_position(const map::Point& point)
  {
    position_ = point;
  }
}
