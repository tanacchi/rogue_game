#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <iostream>
#include <ncurses.h>
#include <memory>

class DisplayPanel
{
public:
  DisplayPanel(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
  ~DisplayPanel();
protected:
  std::unique_ptr<WINDOW> win_;
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
