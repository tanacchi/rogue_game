#include <character/player.hpp>

namespace character
{
  Player::Player(map::Point position)
    : Character(position),
      inventory_{10},
      money_{0}
  {
  }

  const std::map<KeyboardManager::KeyState, const map::Point> Player::motion_table = {
    {KeyboardManager::KeyState::Up,    map::Point{ 0,-1}},
    {KeyboardManager::KeyState::Down,  map::Point{ 0, 1}},
    {KeyboardManager::KeyState::Right, map::Point{ 1, 0}},
    {KeyboardManager::KeyState::Left,  map::Point{-1, 0}},
  };

  std::size_t Player::get_money() const
  {
    return money_;
  }

  void Player::add_money(std::size_t addition)
  {
    money_ += addition;
  }

  std::ostream& operator<<(std::ostream& os, const Player& player)
  {
    os << "\n { position : " << player.position_ << " },\n"
       << " { money : " << player.money_ << " }";
    return os;
  }
}
