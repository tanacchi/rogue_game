#include <map/none.hpp>

namespace map
{
  None::None(std::string type)
    : MapElem(type)
  {
  }

  bool None::is_valid_point() const
  {
    return false;
  }
}
