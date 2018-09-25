#include <map/none.hpp>

namespace map
{
  None::None(std::string type)
    : MapElem(type)
  {
  }

  bool None::can_stand() const
  {
    return false;
  }
}
