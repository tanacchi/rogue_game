#include <iostream>
#include <cstdlib>

#include <game_master/game_master.hpp>
#include <menu/menu_handler.hpp>

int main()
{
  try
  {
    GameMaster  master{};
    GameStatus  status{};
    MenuHandler menu_handler{};
    
    while (status.task != Task::End)
    {
      switch (status.task)
      {
        case Task::Show:
          status = master.show(status);
          break;
        case Task::Input:
          status = master.input(status);
          break;
        case Task::Switch:
          status = master.toggle_mode(status);
          break;
        case Task::Perform:
          if (status.mode == Mode::Dungeon)
          {
            status = master.take_dungeon_mode(status);
          }
          else
          {
            status = menu_handler(master); 
          }
          break;
        case Task::End:
          exit(EXIT_SUCCESS);
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

  return 0;
}
