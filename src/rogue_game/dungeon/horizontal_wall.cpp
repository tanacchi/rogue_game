#include <dungeon/horizontal_wall.hpp>

namespace dungeon
{
  HorizontalWall::HorizontalWall(std::string type)
    : DungeonElem(type)
  {
  }

  bool HorizontalWall::can_stand() const
  {
    return false;
  }
}
