#ifndef INCLUDED_GOLD_ACTION_HPP
#define INCLUDED_GOLD_ACTION_HPP

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <utility/logger.hpp>
#include <item/gold.hpp>

template <typename U>
class GoldAction : public Action<Gold, U>
{
  public:
    using Usage = U;

    GoldAction(const Gold& gold)
      : Action<Gold, U>{}
      , gold_{gold}
    {
    }

  private:
    GameStatus do_it(GameMaster* master, ConsumeTag)
    {
      master->player.add_money(gold_.get_amount());
      return GameStatus{};
    }

    Gold gold_;
};

#endif  // INCLUDED_GOLD_ACTION_HPP
