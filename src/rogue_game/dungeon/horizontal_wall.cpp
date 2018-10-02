#include <dungeon/horizontal_wall.hpp>

namespace dungeon
{
  HorizontalWall::HorizontalWall()
    : DungeonElem("horizontal_wall", false)
  {
  }

  bool HorizontalWall::can_stand() const
  {
    return false;
  }
}
