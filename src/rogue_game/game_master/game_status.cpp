#include <game_master/game_status.hpp>

GameStatus::GameStatus(Task task, Mode) noexcept
  : task{task}
  , mode{mode}
{
}
