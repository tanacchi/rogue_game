#include <map_elem.hpp>

MapElem::MapElem(std::string type)
  : type{type},
    symbol{get_symbol()}
{
}

const char MapElem::get_symbol()
{
  if (type == "horizontal_wall") return '-';
  if (type == "vertical_wall") return '|';
  if (type == "floor") return '.';
  if (type == "path") return '#';
  if (type == "none") return ' ';
}
