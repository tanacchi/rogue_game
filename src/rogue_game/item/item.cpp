#include <item/item.hpp>

namespace item
{
  Item::Item(std::string type, ::map::Point position)
    : MapElem(type),
      position_{position}
  {
  }

  Item::Item(Item&& rhs) noexcept
    : MapElem(type),
      position_{rhs.position_}
  {
  }
  
  ::map::Point Item::get_position() const
  {
    return position_;
  }
}
