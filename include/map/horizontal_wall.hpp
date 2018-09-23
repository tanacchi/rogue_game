#ifndef INCLUDED_HORIZONTAL_HPP
#define INCLUDED_HORIZONTAL_HPP

#include <map/map_elem.hpp>

namespace map
{
  class HorizontalWall : public MapElem
  {
  public:
    HorizontalWall(std::string type);
    bool is_valid_point() const;
  };
}

#endif  // INCLUDED_HORIZONTAL_HPP
