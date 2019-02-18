#include <game_master/game_master.hpp>

int main()
{
  GameMaster master{};
  master.run();

  debug::Logger::log_string("End of main function");
  return 0;
}
