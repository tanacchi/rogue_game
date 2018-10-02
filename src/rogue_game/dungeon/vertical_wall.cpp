#include <dungeon/vertical_wall.hpp>

namespace dungeon
{
  VerticalWall::VerticalWall()
    : DungeonElem("vertical_wall", false)
  {
  }
  bool VerticalWall::can_stand() const
  {
    return false;
  }
}
