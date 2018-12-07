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
    box(win_.get(), 0, 0);
    for (std::size_t i{0}, size{menu_strings_.size()}; i < size; ++i) {
      if (i == selected_index_) {
        wattron(win_.get(), A_REVERSE);
      }
      mvwprintw(win_.get(), 1 + i, 1, " %d : %s ", i, menu_strings_[i].c_str());
      wattrset(win_.get(), A_NORMAL);
    }
    wrefresh(win_.get());
  }

  void MenuDisplay::hide()
  {
    wclear(win_.get());
    selected_index_ = 0;
    wrefresh(win_.get());
  }
  
  void MenuDisplay::toggle_menu(KeyboardManager::KeyState key_state)
  {
    switch (key_state) {
    case KeyboardManager::KeyState::Up:
      if (selected_index_ > 0) {
        --selected_index_;
      }
      break;
    case KeyboardManager::KeyState::Down:
      if (selected_index_ < menu_strings_.size() - 1) {
        ++selected_index_;
      }
      break;
    default:
      break;
    }
  }

  int MenuDisplay::get_current_index() const
  {
    return selected_index_;
  }
}
