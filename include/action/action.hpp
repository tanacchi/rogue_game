#ifndef INCLUDED_ACTION_HPP
#define INCLUDED_ACTION_HPP

#include <memory>

#include <action/usages.hpp>
#include <game_master/game_status.hpp>
#include <utility/logger.hpp>

class GameMaster;

template <typename T, typename U>
class Action
{
  public:
    using Target = T;
    using Usage  = U;
    virtual GameStatus do_action(const std::shared_ptr<GameMaster>& master)
    {
      return do_it(master, Usage{});
    }

  private:
    virtual GameStatus do_it(const std::shared_ptr<GameMaster>& master, NormalTag)
    {
      LOG_STRING("Invalid Action::do_it called. (NormalTag)");
      return GameStatus{Task::End};
    }

    virtual GameStatus do_it(const std::shared_ptr<GameMaster>& master, ConsumeTag)
    {
      LOG_STRING("Invalid Action::do_it called. (ConsumeTag)");
      return GameStatus{Task::End};
    }

    virtual GameStatus do_it(const std::shared_ptr<GameMaster>& master, PutTag)
    {
      LOG_STRING("Invalid Action::do_it called. (PutTag)");
      return GameStatus{Task::End};
    }
};

#endif  // INCLUDED_ACTION_HPP
