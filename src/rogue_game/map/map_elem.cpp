#include <map>

#include <map/map_elem.hpp>

namespace map
{
  MapElem::MapElem(const std::string type)
    : type{type},
      symbol{get_symbol(type)}
  {
  }

  MapElem::MapElem(MapElem&& rhs) noexcept
    : type{rhs.type},
      symbol{rhs.symbol}
  {
  }
  
  const char get_symbol(const std::string type)
  {
    static std::map<std::string, char> symbol_hash = {
      {"horizontal_wall", '-'},
      {"vertical_wall",   '|'},
      {"floor",           '.'},
      {"path",            '#'},
      {"none",            ' '},
      {"door",            '+'},
      {"gold",            '*'}
    };
    return symbol_hash.find(type) != symbol_hash.end() ? symbol_hash.at(type) : '$';
  }
}
