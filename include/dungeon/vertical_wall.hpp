#ifndef INCLUDED_VERTICAL_WALL_HPP
#define INCLUDED_VERTICAL_WALL_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class VerticalWall : public DungeonElem
  {
  public:
    VerticalWall();
    bool can_stand() const;
  };
}

#endif  // INCLUDED_VERTICAL_WALL_HPP
