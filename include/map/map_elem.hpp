#ifndef INCLUDED_MAP_ELEM_HPP
#define INCLUDED_MAP_ELEM_HPP

#include <string>

namespace map
{
  class MapElem {
  public:
    MapElem(std::string type);
    MapElem(MapElem&& rhs) noexcept;
    virtual ~MapElem() = default;
    const std::string type;
    const char symbol;
  };
  
  const char get_symbol(const std::string);
}

#endif  // INCLUDED_MAP_ELEM_HPP
