#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);

  GameMaster master{};
  while (true) {
    master.update();
  }
  return 0;
}
