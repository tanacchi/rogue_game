#ifndef INCLUDED_HORIZONTAL_HPP
#define INCLUDED_HORIZONTAL_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class HorizontalWall : public DungeonElem
  {
  public:
    HorizontalWall(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_HORIZONTAL_HPP
