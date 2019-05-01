#include <character/character.hpp>

Character::Character(Point<int> position)
  : position_{position}
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
