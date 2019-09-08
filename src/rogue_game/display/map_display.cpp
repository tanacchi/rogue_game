#include <display/map_display.hpp>
#include <character/player.hpp>
#include <map/map.hpp>

MapDisplay::MapDisplay(std::size_t x, std::size_t y,
    std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MapDisplay::show(const Map& map, const Player& player)
{
  werase(win_.get());

  // Display dungeon map
  for (std::size_t y{0}; y < map.height; ++y)
  {
    for (std::size_t x{0}; x < map.width; ++x)
    {
      auto visible_symbol{map.dungeon_layer[y][x]->symbol};
      const auto& stepped_item_itr{map.item_layer.find(Point<int>{x, y})};
      if (stepped_item_itr != map.item_layer.end())
        visible_symbol = stepped_item_itr->second->symbol;
      if (map.hidden_layer[y][x])
        visible_symbol = ' ';
      mvwaddch(win_.get(), y, x, visible_symbol);
    }
  }

  mvwaddch(win_.get(), player.get_position().get_y(), player.get_position().get_x(), '@' | A_BOLD);
  auto sight{player.get_position() + player.get_direction()};
  mvwchgat(win_.get(), sight.get_y(), sight.get_x(), 1, A_BOLD | A_UNDERLINE, 0, nullptr);

  wrefresh(win_.get());
}
