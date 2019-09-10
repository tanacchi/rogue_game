#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <map/map.hpp>
#include <character/player.hpp>
#include <display/map_display.hpp>
#include <display/menu_display.hpp>
#include <display/player_display.hpp>
#include <display/message_display.hpp>

class Menu;
class GameStatus;

class GameMaster
{
  public:
    GameMaster();
    ~GameMaster() = default;
    GameStatus show(const GameStatus& status);
    GameStatus input(const GameStatus& status);
    GameStatus perform(const GameStatus& status);
    GameStatus handle_dungeon(const GameStatus& status);

    Map            map;
    MapDisplay     map_display;
    PlayerDisplay  player_display;
    MessageDisplay message_display;
    Player         player;
    std::vector<std::string> messages;
};

#endif  // INCLUDED_GAME_MASTER_HPP
