#include <map/door.hpp>

namespace map
{
  Door::Door(std::string type)
    : MapElem(type)
  {
  }

  bool Door::is_valid_point() const
  {
    return true;
  }
}
