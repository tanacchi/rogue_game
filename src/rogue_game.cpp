#include <game_master/game_master.hpp>

int main()
{
  debug::Logger::log_string("Hello");

  GameMaster master{};
  master.run();

  return 0;
}
