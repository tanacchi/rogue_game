#include <dungeon/path.hpp>

namespace map
{
  Path::Path(std::string type)
    : MapElem(type)
  {
  }

  bool Path::can_stand() const
  {
    return true;
  }
}
