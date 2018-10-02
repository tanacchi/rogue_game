#include <dungeon/floor.hpp>

namespace dungeon
{
  Floor::Floor()
    : DungeonElem("floor", true)
  {
  }

  bool Floor::can_stand() const
  {
    return true;
  }
}
