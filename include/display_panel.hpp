#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

class DisplayPanel
{
public:
  DisplayPanel();
  ~DisplayPanel();
  void draw_outline(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
