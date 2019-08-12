#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <utility/logger.hpp>

const Menu::ContentType Menu::base_content {{
  {"back", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      return GameStatus{};
    }
  },
  {"exit", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      return GameStatus{Task::End};
    }
  },
  {"item", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.reset(new Menu{Menu::item_content});
      return GameStatus{};
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
