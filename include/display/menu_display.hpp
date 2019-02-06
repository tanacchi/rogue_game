#ifndef INCLUDED_MUNU_DISPLAY_HPP
#define INCLUDED_MUNU_DISPLAY_HPP

#include <vector>

#include <display/display_panel.hpp>
#include <keyboard/key_manager.hpp>

namespace menu
{
  class MenuDisplay : public DisplayPanel
  {
  public:
    MenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul);
    void set_menu(std::vector<std::string>&& menu);
    void show() const;
    void hide();
    void toggle_menu(const KeyManager& key_state);
    int get_current_index() const;
  private:
    std::vector<std::string> menu_strings_{};
    std::size_t selected_index_;
  };
}

#endif  // INCLUDED_MUNU_DISPLAY_HPP
