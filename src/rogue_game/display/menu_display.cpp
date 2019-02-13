#include <debug/logger.hpp>
#include <display/menu_display.hpp>

namespace menu
{
  MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool is_visible)
    : DisplayPanel(x, y, width, height),
      selected_index_{},
      is_visible_{is_visible}
  {
  }

  void MenuDisplay::set_menu(std::vector<std::string>&& menu)
  {
    menu_strings_ = menu;
  }

  void MenuDisplay::show() const
  {
    wclear(win_.get());

    if (is_visible_) {
      for (std::size_t i{0}, size{menu_strings_.size()}; i < size; ++i) {
        mvwinsstr(win_.get(), 1 + i, 1, menu_strings_[i].c_str());
      }
      mvwchgat(win_.get(), 1 + selected_index_, 1, 14, A_REVERSE, 1, NULL);
      box(win_.get(), ACS_VLINE, ACS_HLINE);
    }
    wrefresh(win_.get());
  }

  void MenuDisplay::set_visible(bool is_visible)
  {
    is_visible_ = is_visible;
    if (!is_visible_)
    {
      selected_index_ = 0;
    }
  }

  void MenuDisplay::toggle_menu(const KeyManager& key)
  {
    if (key == KeyManager::Up && selected_index_ > 0) {
        --selected_index_;
    } else if (key == KeyManager::Down && selected_index_ < static_cast<int>(menu_strings_.size())-1) {
        ++selected_index_;
    }
  }

  int MenuDisplay::get_current_index() const
  {
    return selected_index_;
  }
}
