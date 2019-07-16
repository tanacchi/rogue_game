#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <game_master/game_status.hpp>
#include <utility/logger.hpp>

std::queue<AnyAction> ActionHandler::actions_;

void ActionHandler::push_action(AnyAction&& action)
{
  actions_.push(action);
  LOG_STRING("ACTION PUSHED ");
  LOG_VALUES(actions_.size());
}

GameStatus ActionHandler::invoke()
{
  return GameStatus{};
}

bool ActionHandler::empty()
{
  return true;
}
