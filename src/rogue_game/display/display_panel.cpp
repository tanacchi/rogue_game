#include <display/display_panel.hpp>

DisplayPanel::DisplayPanel(std::size_t x, std::size_t y,
                           std::size_t width, std::size_t height)
  : win_{}
{
#ifndef DEBUG
  if (!has_initialized_)
  {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    has_initialized_ = true;
  }
  win_.reset(newwin(height, width, y, x));
#endif
}

DisplayPanel::~DisplayPanel()
{
}

bool DisplayPanel::has_initialized_{false};
