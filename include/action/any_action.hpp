#ifndef INCLUDED_ANY_ACTION_HPP
#define INCLUDED_ANY_ACTION_HPP

#include <memory>

class GameStatus;
class GameMaster;

struct ActionHolderBase
{
  virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master) = 0;
};

template <typename T>
struct ActionHolder : public ActionHolderBase
{
  ActionHolder(T&& action);
  virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master);

  T action;
};

class AnyAction
{
  public:
    template <typename T>
    AnyAction(T&& action);
    GameStatus do_action(const std::shared_ptr<GameMaster>& master);

  private:
    std::shared_ptr<ActionHolderBase> action_;
};

#endif  // INCLUDED_ANY_ACTION_HPP
