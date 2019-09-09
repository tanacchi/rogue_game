#ifndef INCLUDED_GOLD_ACTION_HPP
#define INCLUDED_GOLD_ACTION_HPP

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <item/gold.hpp>
#include <action/any_action.hpp>
#include <action/action_handler.hpp>
#include <action/message_action.hpp>

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
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, ConsumeTag)
    {
      master->player.add_money(gold_.get_amount());
      ActionHandler::push(MessageAction<NormalTag>("You gained some gold."));
      return GameStatus{Task::Show, Mode::Dungeon};
    }

    Gold gold_;
};

#endif  // INCLUDED_GOLD_ACTION_HPP
