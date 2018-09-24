#include <map>
#include <character/character.hpp>

namespace character
{
  Character::Character(map::Point point, std::unique_ptr<KeyboardManager>&& km_ptr)
    : point_{point},
      km_ptr_{std::move(km_ptr)}
  {
  }

  map::Point Character::get_point() const
  {
    return point_;
  }

  void Character::update(const map::Map& map)
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
    map::Point next_point{point_ + motion};
    if (map.in_range(next_point) && map.get_elem(next_point)->is_valid_point()) {
      point_ = next_point;
    }
  }
}
