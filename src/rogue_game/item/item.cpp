#include <item/item.hpp>

namespace item
{
  Item::Item(std::string type)
    : MapElem(type)
  {
  }

  Item::Item(Item&& rhs) noexcept
    : MapElem(type)
  {
  }

  std::ostream& operator<<(std::ostream& os, const Item& item)
  {
    os << "{ type : " << item.type << " } ";
    return os;
  }
}
