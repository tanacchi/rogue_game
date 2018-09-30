#include <display/map_display.hpp>

namespace map {
  MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                         std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height)
  {
  }

  void MapDisplay::show(Map map, const character::Character& character)
  {
    for (int y{0}; y < map.height; ++y) {
      for (int x{0}; x < map.width; ++x) {
        mvwprintw(win_, y, x, "%c", map.dungeon_layer[y*map.width+x]->symbol);
      }
      mvwprintw(win_, y, map.width, "\n");
    }
    for (auto item : map.item_layer) {
      Point pos{item->get_position()};
      mvwprintw(win_, pos.get_y(), pos.get_x(), "%c", item->symbol);
    }
    mvwprintw(win_, character.get_position().get_y(), character.get_position().get_x(), "@");
    wrefresh(win_);
  }
}
