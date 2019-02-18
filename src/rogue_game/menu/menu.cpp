#include <menu/menu.hpp>

Menu::Menu(const ContentsType& contents)
  : contents_{contents}
{
}

GameMaster::Task Menu::execute(const std::string& key, std::unique_ptr<Menu>& target_menu_ptr) const
{
  auto found_itr{contents_.find(key)};
  return found_itr->second(target_menu_ptr);
}
