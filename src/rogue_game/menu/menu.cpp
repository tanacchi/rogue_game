#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

const Menu::ContentType Menu::base_content {{
  {"item", [](Menu::MenuPtr& menu_ptr)
    {
      return GameStatus{};
    }
  },
  {"exit", [](Menu::MenuPtr& menu_ptr)
    {
      return GameStatus{Mode::Dungeon, Task::End};
    }
  }
}};

Menu::ContentType Menu::item_content {{
  {"a", [](Menu::MenuPtr& menu_ptr)
    {
      return GameStatus{};
    }
  },
  {"b", [](Menu::MenuPtr& menu_ptr)
    {
      return GameStatus{};
    }
  },
  {"c", [](Menu::MenuPtr& menu_ptr)
    {
      return GameStatus{};
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
