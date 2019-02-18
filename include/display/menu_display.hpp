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
    void set_menu_ptr(const std::shared_ptr<Menu>& menu_ptr);
    void show() const;
    void toggle_cursor(const KeyManager& key);
    const Menu::ContentsType::key_type get_selected_content_name() const;
  private:
    std::weak_ptr<Menu> menu_wptr_;
    std::size_t selected_index_;
};

#endif  // INCLUDED_NEW_MENU_DISPLAY
