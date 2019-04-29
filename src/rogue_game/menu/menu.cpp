#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

const Menu::ContentType Menu::base_content {{
  {"item", []()
    {
      return GameStatus{};
    }
  },
  {"exit", []()
    {
      return GameStatus{Mode::Dungeon, Task::End};
    }
  }
}};

Menu::Menu(const Menu::ContentType& content)
  : content_{content}
{
}

const Menu::ContentType& Menu::get_content() const
{
  return content_;
}
