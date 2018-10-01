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
    Character(map::Point position);
    map::Point get_position() const;
    virtual void update(map::Map& map) = 0;
  protected:
    map::Point position_;
  };
}

#endif  // INCLUDED_CHARACTER_HPP
