#ifndef INCLUDED_MUNU_DISPLAY_HPP
#define INCLUDED_MUNU_DISPLAY_HPP

#include <display/display_panel.hpp>

namespace menu
{
  class MenuDisplay : public DisplayPanel
  {
  public:
    MenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul);
  private:
    int selected_index;
  };
}

#endif  // INCLUDED_MUNU_DISPLAY_HPP
