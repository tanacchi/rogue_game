#include <display/menu_display.hpp>

namespace menu
{
  MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height),
      selected_index_{0}
  {
  }

  void MenuDisplay::set_menu(std::vector<std::string>&& menu)
  {
    menu_strings_ = menu;
  }
}
