#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <game_master/game_status.hpp>

std::queue<AnyAction> ActionHandler::actions_;

void ActionHandler::push_action(AnyAction&& action)
{
}

GameStatus ActionHandler::invoke()
{
  return GameStatus{};
}

bool ActionHandler::empty()
{
  return true;
}
