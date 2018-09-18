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

#endif  // INCLUDED_MAP_HPP
