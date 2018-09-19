#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <iostream>
#include <ncurses.h>

class DisplayPanel
{
public:
  DisplayPanel(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
  ~DisplayPanel();
protected:
  WINDOW *win_;
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
