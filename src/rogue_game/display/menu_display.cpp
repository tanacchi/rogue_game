#include <iterator>

#include <display/menu_display.hpp>
#include <debug/logger.hpp>

MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
  : DisplayPanel(x, y, width, height)
{
}

void MenuDisplay::show(const Menu& menu) const
{
}
