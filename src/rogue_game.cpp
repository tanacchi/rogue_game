#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

int main()
{
  debug::Logger logger{};
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();

  // Log test
  {
    std::string str{"Hello"};
    std::size_t length{str.length()};
    char initial{str[0]};
    logger.log(LOG_LOCATION, str, length, initial);
  }
  
  GameMaster master{};
  while (true) {
    master.update();
  }
  return 0;
}
