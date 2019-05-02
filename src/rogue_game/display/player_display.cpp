#include <display/player_display.hpp>
#include <utility/point.hpp>

PlayerDisplay::PlayerDisplay(std::size_t x, std::size_t y,
                             std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void PlayerDisplay::show(const Player& player)
{
  wclear(win_.get());

  auto pos{player.get_position()};
  auto dir{player.get_direction()};
  mvwprintw(win_.get(), 0, 0, "Position: ");
  mvwprintw(win_.get(), 1, 2, "x: %d", pos.get_x());
  mvwprintw(win_.get(), 2, 2, "y: %d", pos.get_y());
  mvwprintw(win_.get(), 3, 0, "Direction: ");
  mvwprintw(win_.get(), 4, 2, "dx: %d", dir.get_x());
  mvwprintw(win_.get(), 5, 2, "dy: %d", dir.get_y());
  mvwprintw(win_.get(), 6, 0, "money: %d", player.get_money());
  mvwprintw(win_.get(), 7, 0, "HP: %d (max: %d)", player.get_hit_point(), player.get_max_hit_point());

  wrefresh(win_.get());
}
