#include <character/player.hpp>
#include <item/gold.hpp>

namespace character
{
  Player::Player()
    : Character(map::Point<int>{0, 0}),
      inventory_{10},
      direction_{map::down},
      money_{0}
  {
  }

  const std::map<KeyboardManager::KeyState, const map::Point<int>> Player::motion_table = {
    {KeyboardManager::KeyState::Up,    map::up   },
    {KeyboardManager::KeyState::Down,  map::down },
    {KeyboardManager::KeyState::Right, map::right},
    {KeyboardManager::KeyState::Left,  map::left },
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
    if (item_index < inventory_.get_item_num()) {   // ここのチェックはコイツの仕事か？？
      inventory_.use(this, item_index);
    }
  }
  
  std::vector<std::string> Player::get_item_name_array() const
  {
    return inventory_.get_item_name_array();
  }

  ::map::Point<int> Player::get_direction() const
  {
    return direction_;
  }

  void Player::assign_motion(const ::map::Point<int>& next_motion)
  {
    if (next_motion == direction_) {
      set_position(next_motion + get_position());
    } else if (next_motion) {
      direction_ = next_motion;
    }
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
      const auto* const item(dynamic_cast<item::Gold *>((*it).get())); // REFACTOR REQUIRED
      os << *item;
    }
    os << "},\n { capacity : " << inventory.capacity_ << " }\n";
    return os;
  }

  std::size_t Player::Inventory::get_item_num() const
  {
    return items_.size();
  }

  std::vector<std::string> Player::Inventory::get_item_name_array() const
  {
    std::vector<std::string> item_names{};
    for (std::list<std::unique_ptr<item::Item> >::const_iterator it{items_.begin()}, end{items_.end()}; it != end; ++it) {
      item_names.emplace_back((*it)->type);
    }
    return item_names;
  }

  void Player::Inventory::store(std::unique_ptr<item::Item>&& item)
  {
    items_.push_back(std::move(item));
  }

  void Player::Inventory::use(Player* const player_ptr, std::size_t item_index)
  {
    std::list<std::unique_ptr<item::Item> >::iterator taget_item_itr{std::next(items_.begin(), item_index)};
    (*taget_item_itr)->use(player_ptr);
    items_.erase(taget_item_itr);
  }
}
