#include <map/path.hpp>

namespace map
{
  Path::Path(std::string type)
    : MapElem(type)
  {
  }

  bool Path::is_valid_point() const
  {
    return true;
  }
}
