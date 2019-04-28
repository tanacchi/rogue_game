#include <iostream>
#include <game_master/game_master.hpp>

int main()
{
  try
  {
    GameMaster master{};
    master.run();
  }
  catch (std::exception& e)
  {
    endwin();
    LOG_STRING("=== EXCEPTION THROWED ===");
    LOG_VALUES(e.what());
    std::cout << e.what() << std::endl;
  }

  return 0;
}
