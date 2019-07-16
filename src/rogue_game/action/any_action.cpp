#include <action/any_action.hpp>
#include <game_master/game_master.hpp>
#include <game_master/game_master.hpp>

template <typename T>
ActionHolder<T>::ActionHolder(T&& action)
  : action{action}
{
}

template <typename T>
GameStatus ActionHolder<T>::do_action(const std::shared_ptr<GameMaster>& master)
{
  return action.do_action(master);
}

template <typename T>
AnyAction::AnyAction(T&& action)
  : action_{std::make_shared<ActionHolderBase>(action)}
{
}

GameStatus AnyAction::do_action(const std::shared_ptr<GameMaster>& master)
{
  return action_->do_action(master);
}
