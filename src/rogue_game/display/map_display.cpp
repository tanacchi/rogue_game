#include <display/map_display.hpp>

namespace map
{
  MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                         std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height)
  {
  }

  void MapDisplay::show(Map& map, const character::Player& player)
  {
    wclear(win_.get());

    // ダンジョン要素の表示
    for (std::size_t y{0}; y < map.height; ++y) {
      for (std::size_t x{0}; x < map.width; ++x) {
        mvwaddch(win_.get(), y, x, map.dungeon_layer[y*map.width+x]->symbol);
      }
      mvwaddch(win_.get(), y, map.width, '\n');
    }

    // アイテム要素の表示
    for (const std::pair<const Point<int>, std::unique_ptr<::item::Item> >& item : map.item_layer) {
      mvwaddch(win_.get(), item.first.get_y(), item.first.get_x(), item.second->symbol);
    }

    // プレイヤーの表示
    mvwaddch(win_.get(), player.get_position().get_y(), player.get_position().get_x(), '@' | A_BOLD);
    ::map::Point<int> sight{player.get_position() + player.get_direction()};
    mvwchgat(win_.get(), sight.get_y(), sight.get_x(), 1, A_BOLD | A_UNDERLINE, 0, NULL);

    wrefresh(win_.get());
  }
}
