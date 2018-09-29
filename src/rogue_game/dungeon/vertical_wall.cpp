#include <dungeon/vertical_wall.hpp>

namespace dungeon
{
  VerticalWall::VerticalWall(std::string type)
    : DungeonElem(type)
  {
  }
  bool VerticalWall::can_stand() const
  {
    return false;
  }
}
