#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <map/map_elem.hpp>

namespace map
{
  class Floor : public MapElem
  {
  public:
    Floor(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_FLOOR_HPP
