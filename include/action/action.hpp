#ifndef INCLUDED_ACTION_HPP
#define INCLUDED_ACTION_HPP

#include <memory>

#include <game_master/game_status.hpp>

template <typename T>
class UsageTag {};
class ConsumeTag : UsageTag<ConsumeTag> {};
class PutTag : UsageTag<PutTag> {};

class GameMaster;

template <typename T, typename U>
class Action
{
  public:
    using Target = T;
    using Usage  = U;
    GameStatus do_action(const std::shared_ptr<GameMaster>& master);

  private:
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, ConsumeTag);
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, PutTag);
};

#endif  // INCLUDED_ACTION_HPP
