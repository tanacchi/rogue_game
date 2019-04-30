#include <character/player.hpp>
#include <item/item_series.hpp>

Player::Player()
  : Character(zero)
  , direction_{down}
  , inventory_{}
  , money_{}
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

void Player::store_item(const ItemPtr& item_ptr)
{
  inventory_.emplace(item_ptr->type, item_ptr);
}

void Player::dispose_item(std::size_t item_index)
{
  auto used_item_itr{std::next(inventory_.begin(), item_index)};
  inventory_.erase(used_item_itr);
}

std::vector<std::string> Player::get_item_name_array() const
{
  std::vector<std::string> names{};
  for (auto itr{inventory_.begin()}, end{inventory_.end()}; itr != end; ++itr)
  {
    names.emplace_back(itr->first);
  }
  return names;
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
