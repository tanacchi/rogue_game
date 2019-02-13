#include <game_master/game_master.hpp>

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  refresh();

  GameMaster master{};
  master.run();
  return 0;
}
