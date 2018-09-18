#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <iostream>

class DisplayPanel
{
public:
  DisplayPanel(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
  ~DisplayPanel();
  void draw_outline() const noexcept;
private:
  const std::size_t x_;
  const std::size_t y_;
  const std::size_t height_;
  const std::string row_boarder_;
  const std::string col_boarder_;
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
