#include <string>
#include <ncurses.h>

#include <display_panel.hpp>

DisplayPanel::DisplayPanel(std::size_t x, std::size_t y,
                           std::size_t width, std::size_t height)
  : win_{newwin(height, width, y, x)},
    x_{x},
    y_{y},
    height_{height},
    row_boarder_(width, '-'),
    col_boarder_{std::string("|") + std::string(width-2, ' ') + std::string("|")}
{
}

DisplayPanel::~DisplayPanel()
{
  delwin(win_);
}

void DisplayPanel::draw_outline() const noexcept
{
  mvprintw(y_, x_, row_boarder_.data());
  for (std::size_t i{1}; i < height_-1; ++i) {
    mvprintw(y_+i, x_, col_boarder_.data());
  }
  mvprintw(y_+height_-1, x_, row_boarder_.data());
}
