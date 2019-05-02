#include <character/character.hpp>

Character::Character(Point<int> position)
  : position_{position}
  , hit_point_{50}
  , max_hit_point_{100}
{
}

const Point<int>& Character::get_position() const
{
  return position_;
}

void Character::set_position(const Point<int>& point)
{
  position_ = point;
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
  os << " { position : " << character.position_ << " }";
  return os;
}
