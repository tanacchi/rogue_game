#ifndef INCLUDED_FOOD_ACTION_HPP
#define INCLUDED_FOOD_ACTION_HPP

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <utility/logger.hpp>
#include <item/food.hpp>

template <typename U>
class FoodAction : public Action<Food, U>
{
  public:
    using Usage = U;

    FoodAction(const Food& food)
      : Action<Food, U>{}
      , food_{food}
    {
    }

  private:
    GameStatus do_it(GameMaster* master, ConsumeTag)
    {
      LOG_STRING("FoodAction<ConsumeTag>::do_it called");
      master->player.heal(food_.get_amount());
      return GameStatus{};
    }

    GameStatus do_it(GameMaster* master, PutTag)
    {
      return GameStatus{};
    }

    Food food_;
};

#endif  // INCLUDED_FOOD_ACTION_HPP
