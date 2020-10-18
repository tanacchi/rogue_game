#include <character/inventory.hpp>
#include <character/player.hpp>
#include <item/item_series.hpp>

Player::Player()
  : Character(zero)
  , inventory_ptr{std::make_shared<Inventory>()}
  , direction_{down}
  , max_hit_point_{100}
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

Point<int> Player::get_direction() const
{
  return direction_;
}

void Player::assign_motion(const Point<int>& next_motion)
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

std::size_t Player::get_max_hit_point() const noexcept
{
  return max_hit_point_;
}

void Player::heal(std::size_t amount) noexcept
{
  hit_point_ += amount;
  if (hit_point_ > max_hit_point_)
    hit_point_ = max_hit_point_;
}

void Player::hit(std::size_t damage) noexcept
{
  if (hit_point_ < damage)
  {
    hit_point_ = 0ul;
  }
  else
  {
    hit_point_ -= damage;
  }
}
