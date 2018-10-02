#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  DungeonElem::DungeonElem(std::string type, bool can_stand)
    : MapElem(type),
      can_stand_{can_stand}
  {
  }
}
