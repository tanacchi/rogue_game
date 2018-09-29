#include <dungeon/path.hpp>

namespace dungeon
{
  Path::Path(std::string type)
    : DungeonElem(type)
  {
  }

  bool Path::can_stand() const
  {
    return true;
  }
}
