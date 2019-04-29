#include <menu/menu_handler.hpp>
#include <display/menu_display.hpp>

GameStatus MenuHandler::operator()(GameMaster& master)
{
  MenuDisplay menu_display{100, 10, 30, 16};
  Menu menu;

  menu_display.show(menu, selected_index_);

  getch();

  menu_display.hide();

  return GameStatus{};
}
