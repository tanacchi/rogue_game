#include <action/action.hpp>
#include <game_master/game_master.hpp>
#include <game_master/game_status.hpp>

template <typename T, typename U>
GameStatus Action<T, U>::do_action(const std::shared_ptr<GameMaster>& master)
{
  return do_it(master, Usage{});
}
