#include <character/character.hpp>

Character::Character(std::size_t x, std::size_t y, std::unique_ptr<KeyboardManager>&& km_ptr)
  : x_{x}, y_{y},
    km_ptr_{std::move(km_ptr)}
{
}

std::size_t Character::get_x() const
{
  return x_;
}

std::size_t Character::get_y() const
{
  return y_;
}

void Character::update(const map::Map& map)
{
  KeyboardManager::KeyState keystate{km_ptr_->get_key()};
  switch (keystate) {
  case KeyboardManager::KeyState::Up:
    if (y_ > 0) {
      --y_;
    }
    return;
  case KeyboardManager::KeyState::Down:
    if (y_ < map.height - 1) {
      ++y_;
    }
    return;
  case KeyboardManager::KeyState::Right:
    if (x_ < map.width - 1) {
      ++x_;
    }
    return;
  case KeyboardManager::KeyState::Left:
    if (x_ > 0) {
      --x_;
    }
    return;
  }
}
