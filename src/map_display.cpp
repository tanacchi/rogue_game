#include <ncurses.h>

#include <map_display.hpp>

MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                       std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MapDisplay::show(Map map)
{
  for (int y{0}; y < map.height; ++y) {
    for (int x{0}; x < map.width; ++x) {
      mvprintw(y, x, "%c", map.elems[y*map.width+x].symbol);
    }
    mvprintw(y, map.width, "\n");
  }
}
