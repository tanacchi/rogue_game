#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  DungeonElem::DungeonElem(std::string type, bool can_stand)
    : MapElem(type),
      can_stand_{can_stand}
  {
  }

  DungeonElem::DungeonElem(const DungeonElem& rhs)
    : MapElem(rhs.type),
      can_stand_{rhs.can_stand_}
  {
  }

  bool DungeonElem::can_stand() const
  {
    return can_stand_;
  }
}
