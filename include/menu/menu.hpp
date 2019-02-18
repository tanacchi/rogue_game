#ifndef INCLUDED_MENU_HPP
#define INCLUDED_MENU_HPP

#include <functional>
#include <memory>
#include <unordered_map>
#include <game_master/task.hpp>

class Menu
{
  public:
    using ContentsType = std::unordered_map<std::string, std::function<Task(std::shared_ptr<Menu>&)>>;
  
    Menu(const ContentsType& contents);
    Task execute(const std::string& key, std::shared_ptr<Menu>& target_menu_ptr) const;
 
    static const ContentsType base_contents;
  
    ContentsType contents;
};

#endif  // INCLUDED_MENU_HPP
