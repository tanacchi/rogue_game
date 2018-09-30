#include <dungeon/path.hpp>

namespace dungeon
{
  Path::Path()
    : DungeonElem("path")
  {
  }

  bool Path::can_stand() const
  {
    return true;
  }
}
