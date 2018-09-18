#include <map_elem.hpp>

namespace map
{
  MapElem::MapElem(const std::string type)
    : type{type},
      symbol{get_symbol(type)}
  {
  }

  const char get_symbol(const std::string type)
  {
    if (type == "horizontal_wall") return '-';
    if (type == "vertical_wall") return '|';
    if (type == "floor") return '.';
    if (type == "path") return '#';
    if (type == "none") return ' ';
  }
}
