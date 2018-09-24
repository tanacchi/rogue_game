#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <map/map_elem.hpp>

namespace map
{
  class Floor : public MapElem
  {
  public:
    Floor(std::string type);
    bool is_valid_point() const;
  };
}

#endif  // INCLUDED_FLOOR_HPP
