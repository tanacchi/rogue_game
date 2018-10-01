#include <item/item.hpp>

namespace item
{
  Item::Item(std::string type, ::map::Point position)
    : MapElem(type),
      position_{position}
  {
  }

  ::map::Point Item::get_position() const
  {
    return position_;
  }
}
