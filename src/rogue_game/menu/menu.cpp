#include <game_master/game_status.hpp>
#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <action/action_handler.hpp>
#include <action/any_action.hpp>
#include <action/attack_action.hpp>
#include <action/message_action.hpp>

const Menu::ContentType Menu::base_content {{
  {"back", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      return GameStatus{Task::Act, Mode::Dungeon};
    }
  },
  {"exit", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      return GameStatus{Task::End, Mode::Select};
    }
  },
  {"attack", [](Menu::MenuPtr& menu_ptr)
    {
      menu_ptr.release();
      ActionHandler::push(AttackAction<NormalTag>());
      return GameStatus{Task::Act, Mode::Dungeon};
    }
  },
  {"item", [](Menu::MenuPtr& menu_ptr)
    {
      if (Menu::item_content.empty())
      {
        ActionHandler::push(MessageAction<NormalTag>("You don't have any items."));
        return GameStatus{Task::Perform, Mode::Select};
      }
      menu_ptr.reset(new Menu{Menu::item_content});
      return GameStatus{Task::Input, Mode::Select};
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
