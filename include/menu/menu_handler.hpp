#ifndef INCLUDED_MENU_HANDLER_HPP
#define INCLUDED_MENU_HANDLER_HPP

#include <display/menu_display.hpp>
#include <menu/menu.hpp>

class GameStatus;

class MenuHandler
{
  public:
    MenuHandler();
    GameStatus operator()(const std::shared_ptr<GameMaster>& master);
    void set_item_content(const std::shared_ptr<GameMaster>& master);

  private:
    Menu::MenuPtr menu_ptr;
    MenuDisplay   menu_display_;
    size_t        selected_index_;
};

#endif  // INCLUDED_MENU_HANDLER_HPP
