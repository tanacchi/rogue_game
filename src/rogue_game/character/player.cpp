#include <character/player.hpp>
#include <item/gold.hpp>

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

  void Player::store_item(std::unique_ptr<item::Item>&& item)
  {
    inventory_.store(std::move(item));
  }

  void Player::use_item(std::size_t item_index)
  {
    inventory_.use(this, item_index);
  }
  
  std::ostream& operator<<(std::ostream& os, const Player& player)
  {
    os << "\n { position : " << player.position_ << " },\n"
       << " { money : " << player.money_ << " }";
    return os;
  }

  Player::Inventory::Inventory(std::size_t capacity)
    : items_{},
      capacity_{capacity}
{
}

  std::ostream& operator<<(std::ostream& os, const Player::Inventory& inventory)
  {
    os << "\n{ items :\n";
    for (std::list<std::unique_ptr<item::Item> >::const_iterator it{inventory.items_.begin()}, end{inventory.items_.end()};
         it != end; ++it, os.put('\n')) {
      const auto* const item {dynamic_cast<item::Gold *>((*it).get())}; // REFACTOR REQUIRED
      os << *item;
    }
    os << "},\n { capacity : " << inventory.capacity_ << " }\n";
    return os;
  }

  void Player::Inventory::store(std::unique_ptr<item::Item>&& item)
  {
    items_.push_back(std::move(item));
    debug::Logger::log_string("Item just stored", '-');
    LOG_VALUES(*this);
  }

  void Player::Inventory::use(Player* const player_ptr, std::size_t item_index)
  {
    std::list<std::unique_ptr<item::Item> >::iterator taget_item_itr{std::next(items_.begin(), item_index)};
    (*taget_item_itr)->use(player_ptr);
    items_.erase(taget_item_itr);
    debug::Logger::log_string("Item just useed", '-');
    LOG_VALUES(*this);
  }
}
