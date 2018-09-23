#include <map/vertical_wall.hpp>

namespace map
{
  VerticalWall::VerticalWall(std::string type)
    : MapElem(type)
  {
  }
  bool VerticalWall::is_valid_point() const
  {
    return false;
  }
}
