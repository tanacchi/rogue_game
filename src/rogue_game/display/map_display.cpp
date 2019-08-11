#include <display/map_display.hpp>

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
      mvwaddch(win_.get(), y, x, map.dungeon_layer[y][x]->symbol);
    }
    mvwaddch(win_.get(), y, map.width, '\n');
  }
  // Display items
  for (auto item : map.item_layer)
  {
    mvwaddch(win_.get(), item.first.get_y(), item.first.get_x(), item.second->symbol | A_BOLD);
  }

  // Hide unknown area
  for (std::size_t y{0}; y < map.height; ++y)
  {
    for (std::size_t x{0}; x < map.width; ++x)
    {
      if (map.hidden_layer[y][x])
      {
        mvwaddch(win_.get(), y, x, ' ');
      }
    }
    mvwaddch(win_.get(), y, map.width, '\n');
  }
  // Display player position and direction
  mvwaddch(win_.get(), player.get_position().get_y(), player.get_position().get_x(), '@' | A_BOLD);
  auto sight{player.get_position() + player.get_direction()};
  mvwchgat(win_.get(), sight.get_y(), sight.get_x(), 1, A_BOLD | A_UNDERLINE, 0, NULL);

  wrefresh(win_.get());
}
