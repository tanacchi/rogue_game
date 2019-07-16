#ifndef INCLUDED_ANY_ACTION_HPP
#define INCLUDED_ANY_ACTION_HPP

#include <memory>

#include <game_master/game_status.hpp>

class GameMaster;

struct ActionHolderBase
{
  virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master) = 0;
};

template <typename T>
struct ActionHolder : public ActionHolderBase
{
  ActionHolder(T action)
    : action{action}
  {
  }

  virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master)
  {
    return action.do_action(master);
  }

  T action;
};

class AnyAction
{
  public:
    template <typename T>
    AnyAction(T action)
    {
      action_.reset(new ActionHolder<T>{action});
    }

    GameStatus do_action(const std::shared_ptr<GameMaster>& master)
    {
      return action_->do_action(master);
    }

  private:
    std::shared_ptr<ActionHolderBase> action_;
};

#endif  // INCLUDED_ANY_ACTION_HPP
