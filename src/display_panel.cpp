#include <string>
#include <ncurses.h>

#include <display_panel.hpp>

DisplayPanel::DisplayPanel(std::size_t x, std::size_t y,
                           std::size_t width, std::size_t height)
  : win_{newwin(height, width, y, x)},
    x_{x},
    y_{y},
    height_{height}
{
}

DisplayPanel::~DisplayPanel()
{
  delwin(win_);
}
