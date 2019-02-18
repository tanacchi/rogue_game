#ifndef INCLUDED_MENU_HPP
#define INCLUDED_MENU_HPP

#include <functional>
#include <memory>
#include <unordered_map>

#include <game_master/game_master.hpp>

class Menu
{
  public:
    using ContentsType = std::unordered_map<std::string, std::function<GameMaster::Task(std::unique_ptr<Menu>&)>>;

    GameMaster::Task execute(const std::string& key, std::unique_ptr<Menu>& target_menu_ptr) const;
 
  private:
    ContentsType contents;
};

#endif  // INCLUDED_MENU_HPP
