#ifndef INCLUDED_MESSAGE_ACTION_HPP
#define INCLUDED_MESSAGE_ACTION_HPP

#include <action/action.hpp>
#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>

using Message = std::string;

template <typename U>
class MessageAction : public Action<Message, U>
{
  public:
    using Usage = U;

    MessageAction(const Message& message)
      : Action<Message, U>{}
      , message_{message}
    {
    }

  private:
    GameStatus do_it(const std::shared_ptr<GameMaster>& master, NormalTag)
    {
      master->messages.emplace_back(message_);
      return GameStatus{};
    }

    Message message_;
};

#endif  // INCLUDED_MESSAGE_ACTION_HPP
