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

  std::ostream& operator<<(std::ostream& os, const MapElem& elem)
  {
    os << "{ type : " << elem.type << " }, "
       << "{ symbol : '" << elem.symbol << "' }";
    return os;
  }

  const char get_symbol(const std::string type)
  {
    // ダンジョン要素の種類と表示文字の対応表
    static const std::map<std::string, const char> symbol_table = {
      {"horizontal_wall", '-'},
      {"vertical_wall",   '|'},
      {"floor",           '.'},
      {"path",            '#'},
      {"none",            ' '},
      {"door",            '+'},
      {"gold",            '*'}
    };
    const std::map<std::string, const char>::const_iterator found_symbol_itr{symbol_table.find(type)};
    return found_symbol_itr != symbol_table.end() ? found_symbol_itr->second : '$';
  }
}
