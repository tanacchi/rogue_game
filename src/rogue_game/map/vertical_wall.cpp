#include <map/vertical_wall.hpp>

namespace map
{
  VerticalWall::VerticalWall(std::string type)
    : MapElem(type)
  {
  }
  bool VerticalWall::can_stand() const
  {
    return false;
  }
}
