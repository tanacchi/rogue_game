#ifndef INCLUDED_ACTION_HANDLER_HPP
#define INCLUDED_ACTION_HANDLER_HPP

#include <queue>

class GameStatus;
class AnyAction;

class ActionHandler
{
  public:
    static void push_action(AnyAction&& action);
    static GameStatus invoke();
    static bool empty();

  private:
    static std::queue<AnyAction> actions_;
};

#endif  // INCLUDED_ACTION_HANDLER_HPP
