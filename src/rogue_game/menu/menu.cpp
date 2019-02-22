#include <menu/menu.hpp>
#include <debug/logger.hpp>

Menu::Menu(const ContentsType& contents)
  : contents{contents}
{
}

Menu::ContentsType::mapped_type::result_type Menu::execute(const std::string& key, std::shared_ptr<Menu>& target_menu_ptr) const
{
  auto found_itr{contents.find(key)};
  return found_itr->second(target_menu_ptr);
}

const Menu::ContentsType Menu::base_contents{{
  {"hoge", [](std::shared_ptr<Menu>& target_menu_ptr){
    target_menu_ptr.reset();
    return GameStatus{Mode::Dungeon, Task::Show}; }},
  {"fuga", [](std::shared_ptr<Menu>& target_menu_ptr){
    return GameStatus{Mode::Dungeon, Task::End}; }},
}};
