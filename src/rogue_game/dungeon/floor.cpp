#include <dungeon/floor.hpp>

namespace dungeon
{
  Floor::Floor()
    : DungeonElem("floor")
  {
  }

  bool Floor::can_stand() const
  {
    return true;
  }
}
