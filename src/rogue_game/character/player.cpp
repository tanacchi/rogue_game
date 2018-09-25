#include <map>

#include <character/player.hpp>

namespace character
{
  Player::Player(map::Point position, std::unique_ptr<KeyboardManager>&& km_ptr)
    : Character(position),
      km_ptr_{std::move(km_ptr)}
  {
  }
  
  void Player::update(const map::Map& map)
  {
    KeyboardManager::KeyState keystate{km_ptr_->get_key()};
    static std::map<KeyboardManager::KeyState, map::Point> motion_table = {
      {KeyboardManager::KeyState::Up,    map::Point{ 0,-1}},
      {KeyboardManager::KeyState::Down,  map::Point{ 0, 1}},
      {KeyboardManager::KeyState::Right, map::Point{ 1, 0}},
      {KeyboardManager::KeyState::Left,  map::Point{-1, 0}},
    };
    map::Point motion{motion_table.find(keystate) != motion_table.end() ?
        motion_table.at(keystate) : map::Point{0, 0}};
    map::Point next_position{position_ + motion};
    if (map.in_range(next_position) && map.get_elem(next_position)->is_valid_point()) {
      position_ = next_position;
    }
  }
}
