#pragma once

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <action/any_action.hpp>
#include <action/action_handler.hpp>
#include <action/message_action.hpp>
#include <character/enemy.hpp>

template <typename U>
class EnemyAction : public Action<Enemy, U>
{
  public:
    using Usage = U;

    EnemyAction(const std::size_t& damage)
      : Action<Enemy, U>{}
      , damage_{damage}
    {
    }

  private:
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, NormalTag)
    {
      master->player.hit(damage_);
      ActionHandler::push(MessageAction<NormalTag>("The enemy ataccked you !"));
      return GameStatus{Task::Show, Mode::Dungeon};
    }

    std::size_t damage_;
};
