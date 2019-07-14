#include <action/action.hpp>
#include <game_master/game_master.hpp>

template <typename T, typename U>
GameStatus Action<T, U>::do_action(const std::shared_ptr<GameMaster>& master)
{
  return do_it(master, Usage{});
}

template <typename T, typename U>
GameStatus Action<T, U>::do_it(const std::shared_ptr<GameMaster>& master, ConsumeTag)
{
  return GameStatus{};
}

template <typename T, typename U>
GameStatus Action<T, U>::do_it(const std::shared_ptr<GameMaster>& master, PutTag)
{
  return GameStatus{};
}
