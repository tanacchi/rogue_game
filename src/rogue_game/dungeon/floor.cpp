#include <dungeon/floor.hpp>

namespace dungeon
{
  Floor::Floor(std::string type)
    : DungeonElem(type)
  {
  }

  bool Floor::can_stand() const
  {
    return true;
  }
}
