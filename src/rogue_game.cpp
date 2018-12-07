#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

#include <character/character.hpp>

int main()
{
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
