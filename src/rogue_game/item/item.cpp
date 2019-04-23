#include <sstream>

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

  void Item::use(Player* const player_ptr)
  {
  }
  
  std::string Item::to_string() const
  {
    std::stringstream ss;
    ss << ::map::MapElem::to_string();
    return ss.str();
  }
}
