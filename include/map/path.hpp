#ifndef INCLUDED_PATH_HPP
#define INCLUDED_PATH_HPP

#include <map/map_elem.hpp>

namespace map
{
  class Path : public MapElem
  {
  public:
    Path(std::string type);
    bool is_valid_point() const;
  };
}

#endif  // INCLUDED_PATH_HPP
