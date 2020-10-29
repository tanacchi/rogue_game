#pragma once

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <action/message_action.hpp>
#include <character/enemy.hpp>


class Attack
{
  public:
    Attack(std::size_t damage)
      : damage_{damage}
    {
    }

  private:
    std::size_t damage_;
};

template <typename U>
class AttackAction : public Action<Attack, U>
{
  public:
    using Usage = U;

    AttackAction(std::size_t damage = 10ul)
      : Action<Attack, U>{}
      , attack_(damage)
    {
    }

  private:
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, NormalTag)
    {
      const auto target_pos{master->player.get_position() + master->player.get_direction()};
      const auto& enemies{master->enemies};
      const auto enemy_itr{std::find_if(enemies.begin(),
                                        enemies.end(),
                                        [&](const auto& e){
                                          return e.get_position() == target_pos;
                                        })};
      if (enemy_itr == enemies.end())
      {
        ActionHandler::push(MessageAction<NormalTag>("Your attack fanned the air."));
      }
      else
      {
        ActionHandler::push(MessageAction<NormalTag>("Attack!!"));
      }
      return GameStatus{Task::Show, Mode::Dungeon};
    }

    Attack attack_;
};
