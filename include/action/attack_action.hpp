#pragma once

#include <vector>

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <action/message_action.hpp>
#include <character/enemy.hpp>


// Use double dispatch
class Attack
{
  public:
    Attack(std::size_t damage)
      : damage_{damage}
    {
    }

    void operator()(std::list<Enemy>::iterator& enemy_itr) const
    {
      enemy_itr->hit(damage_);
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
      auto& enemies{master->enemies};
      auto enemy_itr{std::find_if(enemies.begin(),
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
        attack_(enemy_itr);
        ActionHandler::push(MessageAction<NormalTag>("Attack!!"));
        if (enemy_itr->get_hit_point() == 0ul)
        {
          enemies.erase(enemy_itr);
        }
      }
      return GameStatus{Task::Show, Mode::Dungeon};
    }

    Attack attack_;
};
