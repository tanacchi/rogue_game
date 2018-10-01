#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <valarray>
#include <memory>

#include <map/map_elem.hpp>
#include <map/point.hpp>
#include <dungeon/dungeon_elem.hpp>
#include <item/item.hpp>

namespace map
{
  struct Map
  {
    int width;
    int height;
    std::valarray<std::shared_ptr<::dungeon::DungeonElem> > dungeon_layer;
    std::vector<std::shared_ptr<::item::Item> > item_layer;
    const std::shared_ptr<::dungeon::DungeonElem> get_dungeon_elem(const Point& point) const;
    const std::shared_ptr<::item::Item> get_item_elem(const Point& point) const;
    bool in_range(const Point& point) const;
    Point index_to_point(std::size_t index);
  };

  Map read_map(const std::string mapfile_name);
  std::shared_ptr<::dungeon::DungeonElem> gen_dungeon_elem(std::string type);
}

#endif  // INCLUDED_MAP_HPP
