#include <dungeon/horizontal_wall.hpp>

namespace map
{
  HorizontalWall::HorizontalWall(std::string type)
    : MapElem(type)
  {
  }

  bool HorizontalWall::can_stand() const
  {
    return false;
  }
}
