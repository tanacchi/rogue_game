#include <display/map_display.hpp>
#include <character/player.hpp>
#include <character/enemy.hpp>
#include <map/map.hpp>

MapDisplay::MapDisplay(std::size_t x, std::size_t y,
    std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MapDisplay::show(const Map& map, const Player& player, const Enemies& enemies)
{
  werase(win_.get());

  const auto get_visible_symbol{
    [&](std::size_t x, std::size_t y){
      const auto& stepped_item_itr{map.item_layer.find(Point<int>{x, y})};
      if (map.hidden_layer[y][x])
        return ' ' | A_NORMAL;
      else if (stepped_item_itr != map.item_layer.end())
        return stepped_item_itr->second->symbol | A_BOLD;
      else
        return map.dungeon_layer[y][x]->symbol;
   }};

  for (std::size_t y{0}; y < map.height; ++y)
  {
    for (std::size_t x{0}; x < map.width; ++x)
    {
      mvwaddch(win_.get(), y, x, get_visible_symbol(x, y));
    }
  }

  for (const auto& enemy : enemies)
  {
    mvwaddch(win_.get(), enemy.get_position().get_y(), enemy.get_position().get_x(), 'E' | A_BOLD);
  }
  mvwaddch(win_.get(), player.get_position().get_y(), player.get_position().get_x(), '@' | A_BOLD);
  const auto& sight{player.get_position() + player.get_direction()};
  mvwchgat(win_.get(), sight.get_y(), sight.get_x(), 1, A_BOLD | A_UNDERLINE, 0, nullptr);

  wrefresh(win_.get());
}
