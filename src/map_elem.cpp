#include <map>

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
    static std::map<std::string, char> symbol_hash = {
      {"horizontal_wall", '-'},
      {"vertical_wall",   '|'},
      {"floor",           '.'},
      {"path",            '#'},
      {"none",            ' '}
    };
    return symbol_hash.at(type);
  }
}
