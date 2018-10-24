#include <display/menu_display.hpp>
#include <debug/logger.hpp>

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

  void MenuDisplay::show() const
  {
    wclear(win_.get());
    for (std::size_t i{0}, size{menu_strings_.size()}; i < size; ++i) {
      LOG_VALUES(i, menu_strings_[i].c_str());
      mvwprintw(win_.get(), i, 0, "%d:%s", i, menu_strings_[i].c_str());
    }
    wrefresh(win_.get());
  }
}
