#ifndef INCLUDED_ACTION_HPP
#define INCLUDED_ACTION_HPP

#include <memory>
#include <game_master/game_status.hpp>

template <typename T>
class UsageTag {};
class ConsumeTag : UsageTag<ConsumeTag> {};
class PutTag : UsageTag<PutTag> {};

class GameMaster;
class GameStatus;

template <typename T, typename U>
class Action
{
  public:
    using Target = T;
    using Usage  = U;
    virtual GameStatus do_action(GameMaster* master)
    {
      return do_it(master, Usage{});
    }

  private:
    virtual GameStatus do_it(GameMaster* master, ConsumeTag) = 0;
    virtual GameStatus do_it(GameMaster* master, PutTag) = 0;
};

#endif  // INCLUDED_ACTION_HPP
