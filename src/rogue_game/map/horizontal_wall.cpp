#include <map/horizontal_wall.hpp>

namespace map
{
  HorizontalWall::HorizontalWall(std::string type)
    : MapElem(type)
  {
  }

  bool HorizontalWall::is_valid_point() const
  {
    return false;
  }
}
