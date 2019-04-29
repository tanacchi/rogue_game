#ifndef INCLUDED_MENU_HANDLER_HPP
#define INCLUDED_MENU_HANDLER_HPP

#include <game_master/game_status.hpp>
#include <menu/menu.hpp>
#include <menu/menu_handler.hpp>

class MenuHandler
{
  public:
    GameStatus operator()(GameMaster& master);
   
  private:
    size_t selected_index_;
};

#endif  // INCLUDED_MENU_HANDLER_HPP
