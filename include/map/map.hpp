#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>
#include <memory>

#include <map/map_elem.hpp>
#include <map/point.hpp>
#include <dungeon/dungeon_elem.hpp>

namespace map
{
  struct Map
  {
    int width;
    int height;
    std::valarray<std::shared_ptr<::dungeon::DungeonElem> > dungeon_layer;
    const std::shared_ptr<::dungeon::DungeonElem> get_dungeon_elem(const Point& point) const;
    bool in_range(const Point& point) const;
  };

  Map read_map(const std::string mapfile_name);
  std::shared_ptr<::dungeon::DungeonElem> gen_dungeon_elem(std::string type);
}

#endif  // INCLUDED_MAP_HPP
