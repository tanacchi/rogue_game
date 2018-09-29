#ifndef INCLUDED_NONE_HPP
#define INCLUDED_NONE_HPP

#include <map/map_elem.hpp>

namespace map
{
  class None : public MapElem
  {
  public:
    None(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_NONE_HPP
