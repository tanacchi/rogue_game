#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>

#include <map_elem.hpp>

struct Map
{
  Map() = default;
  Map(const Map&) = default;
  Map(Map&&) = default;
  int width;
  int height;
  std::valarray<MapElem> elems;
};

Map read_map(const std::string mapfile_name);

#endif  // INCLUDED_MAP_HPP
