#include <iostream>
#include <cstdlib>
#include <csignal>

#include <game_master/game_master.hpp>
#include <menu/menu_handler.hpp>
#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <action/message_action.hpp>

int main()
{
  std::signal(SIGINT, [](int signum) { ActionHandler::push_action(MessageAction<NormalTag>("Exit from menu.")); });
  try
  {
    std::shared_ptr<GameMaster> master{std::make_shared<GameMaster>()};
    GameStatus  status{};
    MenuHandler menu_handler{};

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
        case Task::Switch:
          status = master->toggle_mode(status);
          break;
        case Task::Perform:
          if (status.mode == Mode::Dungeon)
          {
            status = master->handle_dungeon(status);
          }
          else
          {
            status = menu_handler(master);
          }
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
  catch (std::exception& e)
  {
    endwin();
    LOG_STRING("=== EXCEPTION THROWED ===");
    LOG_VALUES(e.what());
    std::cout << e.what() << std::endl;
  }
  exit(EXIT_SUCCESS);

  return 0;
}
