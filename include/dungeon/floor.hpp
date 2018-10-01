#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class Floor : public DungeonElem
  {
  public:
    Floor();
    bool can_stand() const;
  };
}

#endif  // INCLUDED_FLOOR_HPP
