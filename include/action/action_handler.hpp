#ifndef INCLUDED_ACTION_HANDLER_HPP
#define INCLUDED_ACTION_HANDLER_HPP

#include <queue>
#include <memory>

#include <boost/serialization/singleton.hpp>

class GameStatus;
class GameMaster;
class AnyAction;

class ActionHandler : public boost::serialization::singleton<ActionHandler>
{
  public:
    static void push(AnyAction&& action);
    static GameStatus invoke(const std::shared_ptr<GameMaster>& master);
    static bool empty();

  private:
    static std::queue<AnyAction> actions_;
};

#endif  // INCLUDED_ACTION_HANDLER_HPP
