#include <display/menu_display.hpp>
#include <debug/logger.hpp>

namespace menu
{
  MenuDisplay::MenuDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
    : DisplayPanel(x, y, width, height),
      selected_index_{}
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
      mvwinsstr(win_.get(), 1 + i, 1, menu_strings_[i].c_str());
    }
    mvwchgat(win_.get(), 1 + selected_index_, 1, 14, A_REVERSE, 1, NULL);
    box(win_.get(), ACS_VLINE, ACS_HLINE);

    wrefresh(win_.get());
  }

  void MenuDisplay::hide()
  {
    selected_index_ = 0;
    
    wclear(win_.get());
    wrefresh(win_.get());
  }
  
  void MenuDisplay::toggle_menu(KeyManager::KeyType key_state)
  {
    if (key_state == KeyManager::Up && selected_index_ > 0) {
        --selected_index_;
    } else if (key_state == KeyManager::Down && selected_index_ < menu_strings_.size()-1) {
        ++selected_index_;
    }
  }

  int MenuDisplay::get_current_index() const
  {
    return selected_index_;
  }
}
