#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

Menu::ContentType base_content {{
  {"item", []()
    {
      return GameStatus{};
    }
  },
  {"exit", []()
    {
      return GameStatus{};
    }
  }
}};
