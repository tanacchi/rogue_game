#include <dungeon/door.hpp>

namespace dungeon
{
  Door::Door()
    : DungeonElem("door", true)
  {
  }

  bool Door::can_stand() const
  {
    return true;
  }
}
