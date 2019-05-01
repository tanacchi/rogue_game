#ifndef INCLUDED_GAME_STATUS_HPP
#define INCLUDED_GAME_STATUS_HPP

#include <game_master/mode.hpp>
#include <game_master/task.hpp>

struct GameStatus
{
  Mode mode{Mode::Dungeon};
  Task task{Task::Show};
};

#endif  // INCLUDED_GAME_STATUS_HPP
