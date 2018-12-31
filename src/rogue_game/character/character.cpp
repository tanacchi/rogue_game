#include <character/character.hpp>

namespace character
{
  Character::Character(map::Point<int> position)
    : position_{position}
  {
  }

  map::Point<int> Character::get_position() const
  {
    return position_;
  }

  void Character::set_position(const map::Point<int>& point)
  {
    position_ = point;
  }

  std::string Character::to_string() const
  {
    std::stringstream ss;
    ss << " { position : " << position_ << " }";
    return ss.str();
  }

  std::ostream& operator<<(std::ostream& os, const Character& character)
  {
    os << character.to_string();
    return os;
  }
}
