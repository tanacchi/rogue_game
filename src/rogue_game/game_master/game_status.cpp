#include <game_master/game_status.hpp>

GameStatus::GameStatus(Task task, Mode mode) noexcept
  : task{task}
  , mode{mode}
{
}
