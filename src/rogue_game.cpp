#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();

  // Log test
  {
    map::Point point1{2, -3};
    map::Point point2{10, 2};
    LOG_VALUES(point1, point2);
    map::MapElem map_elem{"floor"};
    LOG_VALUES(map_elem);
  }
  
  GameMaster master{};
  while (true) {
    master.update();
  }
  return 0;
}
