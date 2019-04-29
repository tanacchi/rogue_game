#ifndef INCLUDED_MENU_HPP
#define INCLUDED_MENU_HPP

#include <functional>
#include <memory>
#include <map>
#include <game_master/game_status.hpp>

class GameMaster;
class MenuHandler;

class Menu
{
  public:
    friend MenuHandler;
    using MenuPtr = std::unique_ptr<Menu>;
    using ContentType = std::map<std::string, std::function<GameStatus(void)> >;

    Menu(const ContentType& content = base_content);
    const ContentType& get_content() const;
    
  private:
    static const ContentType base_content;
    static ContentType item_content;
    ContentType content_;
};

#endif  // INCLUDED_MENU_HPP
