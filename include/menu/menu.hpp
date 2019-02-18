#ifndef INCLUDED_MENU_HPP
#define INCLUDED_MENU_HPP

#include <functional>
#include <memory>
#include <unordered_map>
#include <game_master/game_status.hpp>

class Menu
{
  public:
    using ContentsType = std::unordered_map<std::string, std::function<GameStatus(std::shared_ptr<Menu>&)>>;
  
    Menu(const ContentsType& contents);
    ContentsType::mapped_type::result_type execute(const std::string& key, std::shared_ptr<Menu>& target_menu_ptr) const;
 
    static const ContentsType base_contents;
  
    ContentsType contents;
};

#endif  // INCLUDED_MENU_HPP
