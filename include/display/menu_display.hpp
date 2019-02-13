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
                std::size_t width = 10ul, std::size_t height = 10ul, bool is_visible = false);
    void set_menu(std::vector<std::string>&& menu);
    void show() const;
    void set_visible(bool is_visible);
    void toggle_menu(const KeyManager& key_state);
    int get_current_index() const;
  private:
    std::vector<std::string> menu_strings_{};
    int selected_index_;
    bool is_visible_;
  };
}

#endif  // INCLUDED_MUNU_DISPLAY_HPP
