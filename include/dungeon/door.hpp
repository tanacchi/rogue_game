#ifndef INCLUDED_DOOR_HPP
#define INCLUDED_DOOR_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class Door : public DungeonElem
  {
  public:
    Door();
    bool can_stand() const;
  };
}

#endif  // INCLUDED_DOOR_HPP
