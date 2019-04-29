#ifndef INCLUDED_NEW_MENU_DISPLAY
#define INCLUDED_NEW_MENU_DISPLAY

#include <display/display_panel.hpp>
#include <keyboard/key_manager.hpp>
#include <menu/menu.hpp>

class MenuDisplay : public DisplayPanel
{
  public:
    MenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul, bool is_visible = false);
    void show(const Menu& menu, size_t highlight_index) const;
    void hide() const;
};

#endif  // INCLUDED_NEW_MENU_DISPLAY
