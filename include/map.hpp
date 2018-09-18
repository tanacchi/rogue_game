#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>

#include <map_elem.hpp>

struct Map
{
  int width;
  int height;
  std::valarray<MapElem> elems;
};

char converter(std::string type);
void read_map(const std::string mapfile_name);

#endif  // INCLUDED_MAP_HPP
