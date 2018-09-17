#include <string>
#include <ncurses.h>

#include <display_panel.hpp>

DisplayPanel::DisplayPanel()
{
  initscr();
  keypad(stdscr, TRUE);
}

DisplayPanel::~DisplayPanel()
{
  endwin();
}

void DisplayPanel::draw_outline(std::size_t x, std::size_t y,
                                std::size_t width, std::size_t height)
{
  std::string row_boarder(width, '-');
  std::string col_boarder {std::string("|") + std::string(width-2, ' ') + std::string("|")};
  mvprintw(y, x, row_boarder.data());
  for (std::size_t i{1}; i < height-1; ++i) {
      mvprintw(y+i, x, col_boarder.data());
  }
  mvprintw(y+height-1, x, row_boarder.data());
}
