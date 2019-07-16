#ifndef INCLUDED_ACTION_HPP
#define INCLUDED_ACTION_HPP

#include <memory>

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
    virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master);

  private:
    virtual GameStatus do_it(const std::shared_ptr<GameMaster>& master, ConsumeTag) = 0;
    virtual GameStatus do_it(const std::shared_ptr<GameMaster>& master, PutTag) = 0;
};

#endif  // INCLUDED_ACTION_HPP
