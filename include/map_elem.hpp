#ifndef INCLUDED_MAP_ELEM_HPP
#define INCLUDED_MAP_ELEM_HPP

#include <string>

class MapElem {
public:
  const std::string type;
  const char symbol;
  MapElem(std::string type);
  const char get_symbol();
};

#endif  // INCLUDED_MAP_ELEM_HPP
