#include <dungeon/door.hpp>

namespace dungeon
{
  Door::Door(std::string type)
    : DungeonElem(type)
  {
  }

  bool Door::can_stand() const
  {
    return true;
  }
}
