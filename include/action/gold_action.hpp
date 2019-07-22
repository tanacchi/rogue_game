#ifndef INCLUDED_GOLD_ACTION_HPP
#define INCLUDED_GOLD_ACTION_HPP

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <utility/logger.hpp>

class Gold;

template <typename U>
class GoldAction : public Action<Gold, U>
{
  public:
    using Usage = U;

    GoldAction()
      : Action<Gold, U>{}
    {
    }

  private:
    GameStatus do_it(GameMaster* master, ConsumeTag)
    {
      LOG_STRING("GoldAction<ConsumeTag>::do_it called");
      master->player.add_money(100);
      return GameStatus{};
    }

    GameStatus do_it(GameMaster* master, PutTag)
    {
      return GameStatus{};
    }
};

#endif  // INCLUDED_GOLD_ACTION_HPP
