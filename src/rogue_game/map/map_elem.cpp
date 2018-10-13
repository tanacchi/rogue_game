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
    static std::map<std::string, const char> symbol_table = {
      {"horizontal_wall", '-'},
      {"vertical_wall",   '|'},
      {"floor",           '.'},
      {"path",            '#'},
      {"none",            ' '},
      {"door",            '+'},
      {"gold",            '*'}
    };
    const std::map<std::string, const char>::const_itr found_symbol_itr{symbol_table.find(type)};
    return found_symbol_itr != symbol_table.end() ? found_symbol_itr->second : '$';
  }
}
