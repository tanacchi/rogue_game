#ifndef INCLUDED_NEW_MENU_DISPLAY
#define INCLUDED_NEW_MENU_DISPLAY

#include <display/display_panel.hpp>
#include <menu/menu.hpp>

class NewMenuDisplay : public DisplayPanel
{
  public:
    void show(const std::unique_ptr<Menu>& menu_ptr) const;
};

#endif  // INCLUDED_NEW_MENU_DISPLAY
