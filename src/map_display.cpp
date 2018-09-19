#include <map_display.hpp>

namespace map {
  MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                         std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height)
  {
  }

  void MapDisplay::show(Map map)
  {
    for (int y{0}; y < map.height; ++y) {
      for (int x{0}; x < map.width; ++x) {
        mvwprintw(win_, y, x, "%c", map.elems[y*map.width+x].symbol);
      }
      mvwprintw(win_, y, map.width, "\n");
    }
    wrefresh(win_);
  }
}
