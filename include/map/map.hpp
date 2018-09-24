#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>
#include <memory>

#include <map/map_elem.hpp>
#include <map/point.hpp>

namespace map
{
  struct Map
  {
    int width;
    int height;
    std::valarray<std::shared_ptr<MapElem> > elems;
    const std::shared_ptr<MapElem> get_elem(const Point& point) const;
    bool in_range(const Point& point) const;
  };

  Map read_map(const std::string mapfile_name);
  std::shared_ptr<MapElem> gen_map_elem(std::string type);
}

#endif  // INCLUDED_MAP_HPP
