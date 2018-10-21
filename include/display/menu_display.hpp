#ifndef INCLUDED_MUNU_DISPLAY_HPP
#define INCLUDED_MUNU_DISPLAY_HPP

#include <display/display_panel.hpp>

namespace menu
{
  class MenuDisplay : public DisplayPanel
  {
    MenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul);
  };
}

#endif  // INCLUDED_MUNU_DISPLAY_HPP
