#include <map>
#include <sstream>

#include <map/map_elem.hpp>

MapElem::MapElem(const std::string type)
  : type{type}
  , symbol{get_symbol(type)}
{
}

MapElem::MapElem(const MapElem& rhs)
  : type{rhs.type}
  , symbol{rhs.symbol}
{
}

MapElem::MapElem(MapElem&& rhs) noexcept
  : type{rhs.type}
  , symbol{rhs.symbol}
{
}

std::string MapElem::to_string() const
{
  std::stringstream ss;
  ss << "{ type : " << type << " }, "
    << "{ symbol : '" << symbol << "' }";
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const MapElem& elem)
{
  os << elem.to_string();
  return os;
}

const chtype get_symbol(const std::string type)
{
  static const std::map<std::string, const chtype> symbol_table = {
    {"horizontal_wall", '-'},
    {"vertical_wall",   '|'},
    {"floor",           '.'},
    {"path",            '#'},
    {"none",            ' '},
    {"door",            '+'},
    {"gold",            '*'},
    {"food",            ':'}
  };
  const std::map<std::string, const chtype>::const_iterator found_symbol_itr{symbol_table.find(type)};
  return found_symbol_itr != symbol_table.end() ? found_symbol_itr->second : '$';
}
