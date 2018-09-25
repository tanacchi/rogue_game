#include <map/floor.hpp>

namespace map
{
  Floor::Floor(std::string type)
    : MapElem(type)
  {
  }

  bool Floor::can_stand() const
  {
    return true;
  }
}
