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

std::size_t Character::get_hit_point() const noexcept
{
  return hit_point_;
}

std::size_t Character::get_max_hit_point() const noexcept
{
  return max_hit_point_;
}

void Character::toggle_hit_point(std::size_t amount)
{
  hit_point_ += amount;
  if (hit_point_ > max_hit_point_)
    hit_point_ = max_hit_point_;
  else if (hit_point_ < 0)
    hit_point_ = 0;
}
