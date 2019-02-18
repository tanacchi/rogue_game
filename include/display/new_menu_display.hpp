#ifndef INCLUDED_NEW_MENU_DISPLAY
#define INCLUDED_NEW_MENU_DISPLAY

#include <display/display_panel.hpp>
#include <menu/menu.hpp>

class NewMenuDisplay : public DisplayPanel
{
  public:
    NewMenuDisplay(std::size_t x, std::size_t y,
                std::size_t width = 10ul, std::size_t height = 10ul, bool is_visible = false);
    void show(const std::unique_ptr<Menu>& menu_ptr) const;
};

#endif  // INCLUDED_NEW_MENU_DISPLAY
