#include <iterator>

#include <display/menu_display.hpp>
#include <debug/logger.hpp>

MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
  : DisplayPanel(x, y, width, height),
    selected_index_{}
{
}

void MenuDisplay::reset_menu(const std::shared_ptr<Menu>& menu_ptr)
{
  menu_wptr_ = menu_ptr;
  selected_index_ = std::size_t{};
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

const Menu::ContentsType::key_type MenuDisplay::get_selected_content_name() const
{
  if (std::shared_ptr<Menu> menu_ptr = menu_wptr_.lock())
  {
    auto selected_content_itr{std::next(menu_ptr->contents.begin(), selected_index_)};
    return selected_content_itr->first;
  }
  else 
  {
    throw std::runtime_error{"Failed to get selected content"};
    return "";
  }
}
