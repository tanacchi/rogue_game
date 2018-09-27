#include <map/door.hpp>

namespace map
{
  Door::Door(std::string type)
    : MapElem(type)
  {
  }

  bool Door::can_stand() const
  {
    return true;
  }
}
