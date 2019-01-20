#include <map/point.hpp>
#include <display/player_display.hpp>

PlayerDisplay::PlayerDisplay(std::size_t x, std::size_t y,
                             std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void PlayerDisplay::show(const character::Player& player)
{
  wclear(win_.get());

  // 変数をループやらマクロやらで一気に参照できたら嬉しいが
  // 言語が違うか
  // 位置情報は logger に任せるつもり
  map::Point<int> pos{player.get_position()};
  mvwprintw(win_.get(), 0, 0, "Position: ");
  mvwprintw(win_.get(), 1, 2, "x: %d", pos.get_x());
  mvwprintw(win_.get(), 2, 2, "y: %d", pos.get_y());
  mvwprintw(win_.get(), 3, 0, "money: %d", player.get_money());

  wrefresh(win_.get());
}
