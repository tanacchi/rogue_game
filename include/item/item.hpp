#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <map/map_elem.hpp>
#include <map/point.hpp>

namespace item
{
  class Item : public ::map::MapElem
  {
  public:
    Item(std::string type);
    Item(Item&& rhs) noexcept;
    virtual ~Item() = default;
    ::map::Point get_position() const;
  };
}

#endif  // INCLUDED_ITEM_HPP
