#ifndef INCLUDED_GAME_STATUS_HPP
#define INCLUDED_GAME_STATUS_HPP

#include <game_master/mode.hpp>
#include <game_master/task.hpp>

struct GameStatus
{

  explicit GameStatus(Task task = Task::Show, Mode mode = Mode::Dungeon) noexcept;

  Task task;
  Mode mode;
};

#endif  // INCLUDED_GAME_STATUS_HPP
