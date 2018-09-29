#ifndef INCLUDED_VERTICAL_WALL_HPP
#define INCLUDED_VERTICAL_WALL_HPP

#include <map/map_elem.hpp>

namespace map
{
  class VerticalWall : public MapElem
  {
  public:
    VerticalWall(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_VERTICAL_WALL_HPP
