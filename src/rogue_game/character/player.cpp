#include <character/player.hpp>
#include <item/item_series.hpp>

Player::Player()
  : Character(zero),
  direction_{down},
  money_{0}
{
}

const std::map<KeyManager::KeyType, const Point<int>> Player::motion_table = {
  {KeyManager::Up,    up   },
  {KeyManager::Down,  down },
  {KeyManager::Right, right},
  {KeyManager::Left,  left },
};

std::size_t Player::get_money() const
{
  return money_;
}

void Player::add_money(std::size_t addition)
{
  money_ += addition;
}

void Player::store_item(::ItemPtr&& item)
{
}

void Player::use_item(std::size_t item_index)
{
}

std::vector<std::string> Player::get_item_name_array() const
{
}

::Point<int> Player::get_direction() const
{
  return direction_;
}

void Player::assign_motion(const ::Point<int>& next_motion)
{
  if (next_motion == direction_)
  {
    set_position(next_motion + get_position());
  }
  else if (next_motion)
  {
    direction_ = next_motion;
  }
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
  os << "\n { position : " << player.position_ << " },\n"
    << " { money : " << player.money_ << " }";
  return os;
}
