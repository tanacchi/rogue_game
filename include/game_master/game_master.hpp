#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <display/map_display.hpp>
#include <display/menu_display.hpp>
#include <display/player_display.hpp>
#include <keyboard/key_manager.hpp>
#include <map/point.hpp>
#include <game_master/game_status.hpp>

class Menu;

// ゲームの進行を扱う
class GameMaster
{
  public:
    GameMaster();
    ~GameMaster();

    GameStatus show(const GameStatus& status);
    GameStatus input(const GameStatus& status);
    GameStatus toggle_mode(const GameStatus& status);
    GameStatus perform(const GameStatus& status);
    GameStatus handle_dungeon(const GameStatus& status);

    Map           map;
    MapDisplay    map_display;
    PlayerDisplay player_display;
    KeyManager    keyboard;
    Player        player;
};

#endif  // INCLUDED_GAME_MASTER_HPP
