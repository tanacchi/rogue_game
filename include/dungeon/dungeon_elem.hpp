#ifndef INCLUDED_DUNGEON_ELEM_HPP
#define INCLUDED_DUNGEON_ELEM_HPP

#include <map/map_elem.hpp>

namespace dungeon
{
  class DungeonElem : public ::map::MapElem
  {
  public:
    DungeonElem(std::string type, bool can_stand);
    virtual ~DungeonElem() = default;
    virtual bool can_stand() const = 0;
  public:
    bool can_stand_;
  };
}

#endif  // INCLUDED_DUNGEON_ELEM_HPP
