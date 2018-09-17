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
