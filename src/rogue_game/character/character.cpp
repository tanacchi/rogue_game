#include <character/character.hpp>

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
  std::size_t x{point_.get_x()};
  std::size_t y{point_.get_y()};
  switch (keystate) {
  case KeyboardManager::KeyState::Up:
    if (y > 0) {
      --y;
    }
    break;
  case KeyboardManager::KeyState::Down:
    if (y < map.height - 1) {
      ++y;
    }
    break;
  case KeyboardManager::KeyState::Right:
    if (x < map.width - 1) {
      ++x;
    }
    break;
  case KeyboardManager::KeyState::Left:
    if (x > 0) {
      --x;
    }
    break;
  }
  if (map.elems[y*map.width + x]->is_valid_point()) {
     point_ = map::Point{x, y};
  } 
}
