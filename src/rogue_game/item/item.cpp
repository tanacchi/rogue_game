#include <sstream>

#include <item/item.hpp>

Item::Item(std::string type)
  : MapElem(type)
{
}

Item::Item(Item&& rhs) noexcept
: MapElem(type)
{
}

std::string Item::to_string() const
{
  std::stringstream ss;
  ss << MapElem::to_string();
  return ss.str();
}
