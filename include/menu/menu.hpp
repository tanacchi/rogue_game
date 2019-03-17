#ifndef INCLUDED_MENU_HPP
#define INCLUDED_MENU_HPP

#include <functional>
#include <memory>
#include <map>
#include <game_master/game_status.hpp>

class GameMaster;

class Menu
{
  public:
    using ContentsType = std::map<std::string, std::function<GameStatus(std::shared_ptr<Menu>&)>>;
  
    Menu(const ContentsType& contents, GameMaster* gm = nullptr);
    ContentsType::mapped_type::result_type execute(const std::string& key, std::shared_ptr<Menu>& target_menu_ptr) const;
 
    static const ContentsType base_contents;
    static const ContentsType item_contents;
  
    ContentsType contents;
};

#endif  // INCLUDED_MENU_HPP
