#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <map/map_elem.hpp>
#include <map/point.hpp>

namespace item
{
  class Item : public ::map::MapElem
  {
  public:
    Item(std::string type, ::map::Point position);
  private:
    ::map::Point position_;
  };
}

#endif  // INCLUDED_ITEM_HPP
