#include <display/menu_display.hpp>
#include <debug/logger.hpp>

MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
  : DisplayPanel(x, y, width, height),
    selected_index_{}
{
}

void MenuDisplay::set_menu_ptr(const std::shared_ptr<Menu>& menu_ptr)
{
  menu_wptr_ = menu_ptr;
}

void MenuDisplay::show() const
{
  wclear(win_.get());
  if (std::shared_ptr<Menu> menu_ptr = menu_wptr_.lock())
  {
    int col{1};
    for (auto itr{menu_ptr->contents.begin()}, end{menu_ptr->contents.end()}; itr != end; ++itr, ++col)
    {
      mvwinsstr(win_.get(), col, 1, itr->first.c_str());
    }
    mvwchgat(win_.get(), 1 + selected_index_, 1, 14, A_REVERSE, 1, NULL);
    box(win_.get(), ACS_VLINE, ACS_HLINE);
  }
  wrefresh(win_.get());
}

void MenuDisplay::toggle_cursor(const KeyManager& key)
{
  if (std::shared_ptr<Menu> menu_ptr = menu_wptr_.lock())
  {
    if (key == KeyManager::Up && selected_index_ != 0)
    {
      --selected_index_;
    }
    else if (key == KeyManager::Down && selected_index_ < menu_ptr->contents.size() - 1)
    {
      ++selected_index_;
    }
  }
}
