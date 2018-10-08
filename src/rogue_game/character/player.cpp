#include <character/player.hpp>

namespace character
{
  Player::Player(map::Point position)
    : Character(position),
      money_{0}
  {
  }

  const std::map<KeyboardManager::KeyState, map::Point> Player::motion_table = {
    {KeyboardManager::KeyState::Up,    map::Point{ 0,-1}},
    {KeyboardManager::KeyState::Down,  map::Point{ 0, 1}},
    {KeyboardManager::KeyState::Right, map::Point{ 1, 0}},
    {KeyboardManager::KeyState::Left,  map::Point{-1, 0}},
  };

  std::size_t Player::get_money() const
  {
    return money_;
  }

  void Player::update(map::Map& map)
  {
    update(map, ::KeyboardManager::KeyState::Unknown);
  }
  
  void Player::update(map::Map& map, const ::KeyboardManager::KeyState keystate)
  {
    // for (std::vector<std::unique_ptr<::item::Item> >::iterator it{map.item_layer.begin()}, end{map.item_layer.end()}; it != end; ++it) {
    //   if ((*it)->get_position() == next_position) {
    //     money_ += 100;
    //     map.item_layer.erase(it);
    //     break;
    //   }
    // }
  }
}
