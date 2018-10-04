#include <rogue_game/game_master.hpp>

GameMaster::GameMaster()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
}

GameMaster::~GameMaster()
{
  endwin();
}
