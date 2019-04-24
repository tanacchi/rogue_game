#include <functional>

#include <game_master/game_master.hpp>
#include <item/item.hpp>
#include <menu/menu.hpp>
#include <debug/logger.hpp>

Menu::Menu(const ContentsType& contents, GameMaster* gm_ptr)
  : contents{contents}
{
  if (gm_ptr != nullptr)
  {
    Menu::item_contents.clear();
    for (const auto& item_ptr : gm_ptr->player_.inventory_.items_)
    {
      ContentsType::key_type key{item_ptr->type};
      std::function<void(void)> item_action{std::bind(&Item::use, *item_ptr, &gm_ptr->player_)};
      ContentsType::mapped_type value{[&](std::shared_ptr<Menu>& target_menu_ptr){
        item_action();
        target_menu_ptr.reset();
        return GameStatus{Mode::Dungeon, Task::Show};
      }};
      LOG_STRING("Debug string");
      Menu::item_contents.insert(std::make_pair(key, value));
    }
    ContentsType::mapped_type back_to_base{[&](std::shared_ptr<Menu>& target_menu_ptr) {
      target_menu_ptr.reset(new Menu{Menu::base_contents});
      return GameStatus{Mode::Dungeon, Task::Show};
    }};
    Menu::item_contents.insert(std::make_pair("back", back_to_base));
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

Menu::ContentsType Menu::item_contents{{
  {"back", [](std::shared_ptr<Menu>& target_menu_ptr)
    {
      target_menu_ptr.reset(new Menu{Menu::base_contents});
      return GameStatus{Mode::Select, Task::Show};
    }},
}};
