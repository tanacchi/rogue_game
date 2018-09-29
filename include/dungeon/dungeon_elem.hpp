#ifndef INCLUDED_DUNGEON_ELEM_HPP
#define INCLUDED_DUNGEON_ELEM_HPP

#include <map/map_elem.hpp>

namespace dungeon
{
  class DungeonElem : public ::map::MapElem
  {
  public:
    DungeonElem(std::string type);
  };
}

#endif  // INCLUDED_DUNGEON_ELEM_HPP
