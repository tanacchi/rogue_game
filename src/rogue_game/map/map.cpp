#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <map/map.hpp>
#include <dungeon/floor.hpp>
#include <dungeon/path.hpp>
#include <dungeon/none.hpp>
#include <dungeon/horizontal_wall.hpp>
#include <dungeon/vertical_wall.hpp>
#include <dungeon/door.hpp>

#include <item/gold.hpp>

namespace map
{
  Map::Map(Map&& map)
    : width{map.width},
      height{map.height},
      initial_position{std::move(map.initial_position)},
      dungeon_layer{std::move(map.dungeon_layer)},
      item_layer{std::move(map.item_layer)}
  {
  }

  Map& Map::operator=(Map&& map) noexcept
  {
    width = map.width; height = map.height;
    initial_position = std::move(map.initial_position);
    dungeon_layer = std::move(map.dungeon_layer);
    item_layer = std::move(map.item_layer);
    return *this;
  }

  std::ostream& operator<<(std::ostream& os, const Map& map)
  {
    os << "{ width : " << map.width << " }, { height : " << map.height << "},\n"
       << "{ initial_position : " << map.initial_position << " },\n "
       << "{ dungeon_layer :\n";
    for (std::size_t y{0}; y < map.height; ++y, os.put('\n')) {
      for (std::size_t x{0}; x < map.width; ++x) {
        os << map.get_dungeon_elem(map::Point<int>{x, y}).symbol;
      }
    }
    return os;
  }

  // いまのところダンジョン要素の配列を一次元にしているメリットが
  // json からの読み込み位なので
  // そのを解消して二次元に切り替えて見ようかと思う
  const ::dungeon::DungeonElem Map::get_dungeon_elem(const Point<int>& point) const
  {
    const ::dungeon::DungeonElem* elem{dungeon_layer[width * point.get_y() + point.get_x()].get()};
    return *elem;
  }

  bool Map::in_range(const Point<std::size_t>& point) const
  {
    std::size_t x{point.get_x()}, y{point.get_y()};
    return (0 <= x && x < width) && (0 <= y && y < height);
  }

  Point<int> Map::index_to_point(std::size_t index)
  {
    return {index % width, index / width};
  }

}
