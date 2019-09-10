#include <iostream>
#include <cstdlib>
#include <csignal>

#include <game_master/game_master.hpp>
#include <menu/menu_handler.hpp>
#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <action/message_action.hpp>

namespace {
  class SigintHandler {};
}

int main()
{
  GameStatus status{Task::Show, Mode::Dungeon};
  std::shared_ptr<GameMaster> master{std::make_shared<GameMaster>()};
  MenuHandler menu_handler{};

try_begin:
  try
  {
    std::signal(SIGINT, [](int signal){ throw SigintHandler{};});
    while (status.task != Task::End)
    {
      switch (status.task)
      {
        case Task::Show:
          status = master->show(status);
          break;
        case Task::Input:
          status = master->input(status);
          break;
        case Task::Perform:
          status = status.mode == Mode::Dungeon ? master->handle_dungeon(status) : menu_handler(master);
          break;
        case Task::Act:
          while (!ActionHandler::empty())
          {
            ActionHandler::invoke(master);
          }
          status.task = Task::Show;
          break;
        default:
          throw std::domain_error{"Invalid task detected."};
      }
    }
  }
  catch (SigintHandler&)
  {
    ActionHandler::push(MessageAction<NormalTag>("Exit from menu."));
    status.task = Task::Act;
    goto try_begin;
  }
  catch (std::exception& e)
  {
    endwin();
    LOG_STRING("=== EXCEPTION THROWED ===");
    LOG_VALUES(e.what());
    std::cout << e.what() << std::endl;
  }

  endwin();
  exit(EXIT_SUCCESS);

  return 0;
}
