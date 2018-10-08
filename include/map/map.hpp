#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>
#include <memory>
#include <map>

#include <map/map_elem.hpp>
#include <map/point.hpp>
#include <dungeon/dungeon_elem.hpp>
#include <item/item.hpp>

namespace map
{
  struct Map
  {
    Map() = default;
    Map(Map&& map);
    std::size_t width;
    std::size_t height;
    map::Point initial_position;
    std::vector<std::unique_ptr<::dungeon::DungeonElem> > dungeon_layer;
    std::map<Point, std::unique_ptr<::item::Item> > item_layer;
    const ::dungeon::DungeonElem get_dungeon_elem(const Point& point) const;
    bool in_range(const Point& point) const;
    Point index_to_point(std::size_t index);
  };

  Map read_map(const std::string mapfile_name);
  std::unique_ptr<::dungeon::DungeonElem> gen_dungeon_elem(std::string type);
}

#endif  // INCLUDED_MAP_HPP
