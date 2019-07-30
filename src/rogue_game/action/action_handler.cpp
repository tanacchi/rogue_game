#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <game_master/game_status.hpp>
#include <utility/logger.hpp>

std::queue<AnyAction> ActionHandler::actions_;

void ActionHandler::push_action(AnyAction&& action)
{
  actions_.push(action);
}

GameStatus ActionHandler::invoke(GameMaster* master)
{
  const auto current_action{actions_.front()};
  actions_.pop();
  return current_action.do_action(master);
}

bool ActionHandler::empty()
{
  return actions_.empty();
}
