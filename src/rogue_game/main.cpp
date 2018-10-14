#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

int main()
{
  debug::Logger logger{};
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();
  
  GameMaster master{};
  while (true) {
    master.update();
  }
  return 0;
}
