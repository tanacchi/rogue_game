#include <map/map.hpp>
#include <utility/logger.hpp>

Map::Map(Map&& map)
  : width{map.width}
  , height{map.height}
  , initial_position{std::move(map.initial_position)}
  , dungeon_layer{std::move(map.dungeon_layer)}
  , item_layer{std::move(map.item_layer)}
  , hidden_layer{std::move(map.hidden_layer)}
{
}

Map& Map::operator=(Map&& map) noexcept
{
  width = map.width; height = map.height;
  initial_position = std::move(map.initial_position);
  dungeon_layer = std::move(map.dungeon_layer);
  item_layer = std::move(map.item_layer);
  hidden_layer = std::move(map.hidden_layer);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
  os << "{ width : " << map.width << " }, { height : " << map.height << "},\n"
    << "{ initial_position : " << map.initial_position << " },\n "
    << "{ dungeon_layer :\n";
  for (std::size_t y{0}; y < map.height; ++y, os.put('\n'))
  {
    for (std::size_t x{0}; x < map.width; ++x)
    {
      os << map.get_dungeon_elem(Point<int>{x, y}).symbol;
    }
  }
  return os;
}

const DungeonElem Map::get_dungeon_elem(const Point<int>& point) const
{
  return *dungeon_layer[point.get_y()][point.get_x()];
}

bool Map::in_range(const Point<std::size_t>& point) const
{
  std::size_t x{point.get_x()}, y{point.get_y()};
  return (0 <= x && x < width) && (0 <= y && y < height);
}

void Map::make_apparent(const Point<std::size_t>& point)
{
  std::size_t range{2ul};
  LOG_STRING("make_apparent called");
  LOG_VALUES(point.get_x(), point.get_y());
  for (auto y{std::max(point.get_y()-range, 0ul)}, y_limit{std::min(point.get_y()+range, height)}; y <= y_limit; ++y)
  {
    for (auto x{std::max(point.get_x()-range, 0ul)}, x_limit{std::min(point.get_x()+range, width)}; x <= x_limit; ++x)
    {
      LOG_VALUES(x, y);
      if (in_range(Point<std::size_t>{x, y}))
      {
        hidden_layer[y][x] = false;
      }
    }
  }
}
