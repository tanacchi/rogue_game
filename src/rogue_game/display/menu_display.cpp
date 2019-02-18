#include <display/menu_display.hpp>
#include <debug/logger.hpp>

MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
  : DisplayPanel(x, y, width, height)
{
}

void MenuDisplay::set_menu_ptr(const std::shared_ptr<Menu>& menu_ptr)
{
  menu_wptr_ = menu_ptr;
}

void MenuDisplay::show(const std::shared_ptr<Menu>& menu_ptr) const
{
  wclear(win_.get());
  LOG_VALUES(!menu_ptr);
  if (menu_ptr)
  {
    int col{1};
    for (auto itr{menu_ptr->contents.begin()}, end{menu_ptr->contents.end()}; itr != end; ++itr, ++col)
    {
      mvwinsstr(win_.get(), col, 1, itr->first.c_str());
    }
  }
  wrefresh(win_.get());
}
