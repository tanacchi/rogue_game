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
    using ContentType = std::map<std::string, std::function<GameStatus(void)> >;
    
  private:
    static const ContentType base_content;
    ContentType content;
};

#endif  // INCLUDED_MENU_HPP
