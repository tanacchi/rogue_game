#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <cstddef>
#include <memory>

#include <keyboard/keyboard_manager.hpp>
#include <map/map.hpp>
#include <map/point.hpp>

class Character
{
public:
  Character(map::Point point, std::unique_ptr<KeyboardManager>&& km_ptr=nullptr);
  map::Point get_point() const;
  void update(const map::Map& map);
private:
  map::Point point_;
  std::unique_ptr<KeyboardManager> km_ptr_;
};

#endif  // INCLUDED_CHARACTER_HPP