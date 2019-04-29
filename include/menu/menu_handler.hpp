#ifndef INCLUDED_MENU_HANDLER_HPP
#define INCLUDED_MENU_HANDLER_HPP

#include <display/menu_display.hpp>
#include <game_master/game_status.hpp>
#include <menu/menu.hpp>
#include <character/player.hpp>

class MenuHandler
{
  public:
    MenuHandler();
    GameStatus operator()(GameMaster& master);
    void set_item_content(Player& player);
   
  private:
    Menu::MenuPtr menu_ptr;
    MenuDisplay   menu_display_;
    size_t        selected_index_;
};

#endif  // INCLUDED_MENU_HANDLER_HPP
