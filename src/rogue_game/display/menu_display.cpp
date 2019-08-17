#include <iterator>

#include <display/menu_display.hpp>
#include <keyboard/key_manager.hpp>
#include <menu/menu.hpp>

MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
  , cursor_width_{width-2}
{
}

void MenuDisplay::show(const Menu& menu, std::size_t highlight_index) const
{
  werase(win_.get());
  auto content{menu.get_content()};
  for (auto itr{content.begin()}, end{content.end()}; itr != end; ++itr)
  {
    mvwinsstr(win_.get(), std::distance(content.begin(), itr) + 1, 1, itr->first.c_str());
  }
  mvwchgat(win_.get(), highlight_index + 1, 1, cursor_width_, A_REVERSE, 1, NULL);
  box(win_.get(), ACS_VLINE, ACS_HLINE);
  wrefresh(win_.get());
}

void MenuDisplay::hide() const
{
  werase(win_.get());
  wrefresh(win_.get());
}
