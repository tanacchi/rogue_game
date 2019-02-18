#include <menu/menu.hpp>

GameMaster::Task Menu::execute(const std::string& key, std::unique_ptr<Menu>& target_menu_ptr) const
{
  auto found_itr{contents.find(key)};
  return found_itr->second(target_menu_ptr);
}
