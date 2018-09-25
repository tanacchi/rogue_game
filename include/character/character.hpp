#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <cstddef>
#include <memory>

#include <keyboard/keyboard_manager.hpp>
#include <map/map.hpp>
#include <map/point.hpp>

namespace character
{
  class Character
  {
  public:
    Character(map::Point point);
    map::Point get_point() const;
    virtual void update(const map::Map& map);
  protected:
    map::Point point_;
  };
}

#endif  // INCLUDED_CHARACTER_HPP
