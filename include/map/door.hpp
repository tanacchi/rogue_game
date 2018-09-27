#ifndef INCLUDED_DOOR_HPP
#define INCLUDED_DOOR_HPP

#include <map/map_elem.hpp>

namespace map
{
  class Door : public MapElem
  {
  public:
    Door(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_DOOR_HPP
