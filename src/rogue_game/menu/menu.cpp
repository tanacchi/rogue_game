#include <game_master/game_master.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

Menu::Menu(const ContentsType& contents, GameMaster* gm_ptr)
  : contents{contents}
{
  if (gm_ptr != nullptr)
  {
    for (const auto& item_name : gm_ptr->player_.get_item_name_array())
    {
      LOG_VALUES(item_name);
    }
  }
}

Menu::ContentsType::mapped_type::result_type Menu::execute(const std::string& key, std::shared_ptr<Menu>& target_menu_ptr) const
{
  auto found_itr{contents.find(key)};
  return found_itr->second(target_menu_ptr);
}

const Menu::ContentsType Menu::base_contents{{
  {"item", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      target_menu_ptr.reset(new Menu{Menu::item_contents});
      return GameStatus{Mode::Select, Task::Show};
    }},
  {"back", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      target_menu_ptr.reset();
      return GameStatus{Mode::Dungeon, Task::Show}; 
    }},
  {"exit", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      return GameStatus{Mode::Dungeon, Task::End}; 
    }},
}};

const Menu::ContentsType Menu::item_contents{{
  {"back", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      target_menu_ptr.reset(new Menu{Menu::base_contents});
      return GameStatus{Mode::Select, Task::Show};
    }},
  {"ahi", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      target_menu_ptr.reset();
      return GameStatus{Mode::Dungeon, Task::Show}; 
    }},
  {"hoge", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      return GameStatus{Mode::Dungeon, Task::End}; 
    }},
}};


