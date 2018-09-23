#include <map/floor.hpp>

namespace map
{
  Floor::Floor(std::string type)
    : MapElem(type)
  {
  }

  bool Floor::is_valid_point() const
  {
    return true;
  }
}
