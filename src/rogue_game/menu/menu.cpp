#include <menu/menu.hpp>
#include <debug/logger.hpp>

Menu::Menu(const ContentsType& contents)
  : contents{contents}
{
}

Task Menu::execute(const std::string& key, std::unique_ptr<Menu>& target_menu_ptr) const
{
  auto found_itr{contents.find(key)};
  return found_itr->second(target_menu_ptr);
}

const Menu::ContentsType Menu::base_contents{{
  {"hoge", [](std::unique_ptr<Menu>& target_menu_ptr){
    debug::Logger::log_string("HOGE detected");
    return Task::Show; }},
  {"fuga", [](std::unique_ptr<Menu>& target_menu_ptr){
    debug::Logger::log_string("FUGA detected");
    return Task::Show; }},
}};
