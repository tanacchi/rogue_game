#ifndef INCLUDED_NEW_MENU_DISPLAY
#define INCLUDED_NEW_MENU_DISPLAY

#include <display/display_panel.hpp>
#include <keyboard/key_manager.hpp>

class Menu;

class MenuDisplay : public DisplayPanel
{
  public:
    MenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul);
    void show(const Menu& menu, std::size_t highlight_index) const;
    void hide() const;

  private:
    std::size_t cursor_width_;
};

#endif  // INCLUDED_NEW_MENU_DISPLAY
