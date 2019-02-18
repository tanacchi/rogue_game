#include <display/new_menu_display.hpp>
#include <debug/logger.hpp>

NewMenuDisplay::NewMenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
  : DisplayPanel(x, y, width, height)
{
}

void NewMenuDisplay::show(const std::unique_ptr<Menu>& menu_ptr) const
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
