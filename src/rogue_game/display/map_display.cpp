#include <display/map_display.hpp>

namespace map {
  MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                         std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height)
  {
  }

  void MapDisplay::show(Map& map, const character::Player& player)
  {
    // ダンジョン要素の表示
    for (std::size_t y{0}; y < map.height; ++y) {
      for (std::size_t x{0}; x < map.width; ++x) {
        mvwprintw(win_.get(), y, x, "%c", map.dungeon_layer[y*map.width+x]->symbol);
      }
      mvwprintw(win_.get(), y, map.width, "\n");
    }

    // アイテム要素の表示
    for (const std::pair<const Point<int>, std::unique_ptr<::item::Item> >& item : map.item_layer) {
      mvwprintw(win_.get(), item.first.get_y(), item.first.get_x(), "%c", item.second->symbol);
    }

    // プレイヤーの表示
    mvwprintw(win_.get(), player.get_position().get_y(), player.get_position().get_x(), "@");
    ::map::Point<int> sight{player.get_position() + player.get_direction()};
    // wmove(win_.get(), sight.get_y(), sight.get_x());
    mvwprintw(win_.get(), sight.get_y(), sight.get_x(), "~");
    wrefresh(win_.get());
  }
}
