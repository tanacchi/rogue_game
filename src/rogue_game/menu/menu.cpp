#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

const Menu::ContentType Menu::base_content {{
  {"item", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.reset(new Menu{Menu::item_content});
      return GameStatus{};
    }
  },
  {"exit", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      return GameStatus{Mode::Dungeon, Task::End};
    }
  }
}};

Menu::ContentType Menu::item_content{};

Menu::Menu(const Menu::ContentType& content)
  : content_{content}
{
}

const Menu::ContentType& Menu::get_content() const
{
  return content_;
}
