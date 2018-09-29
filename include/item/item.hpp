#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <map/map_elem.hpp>

namespace item
{
  class Item : public ::map::MapElem
  {
  public:
    Item(std::string type);
  };
}

#endif  // INCLUDED_ITEM_HPP
