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
    LOG_STRING("=== EXCEPTION THROWED ===");
    LOG_VALUES(e.what());
  }

  return 0;
}
