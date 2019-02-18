#include <display/new_menu_display.hpp>

void NewMenuDisplay::show(const std::unique_ptr<Menu>& menu_ptr) const
{
  wclear(win_.get());
  if (!menu_ptr)
  {
    int col{1};
    for (auto itr{menu_ptr->contents.begin()}, end{menu_ptr->contents.end()}; itr != end; ++itr, ++col)
    {
      mvwinsstr(win_.get(), col, 1, itr->first.c_str());
    }
  }
  wrefresh(win_.get());
}
