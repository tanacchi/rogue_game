#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <random>
#include <map/map.hpp>
#include <character/player.hpp>
#include <character/enemy.hpp>
#include <display/map_display.hpp>
#include <display/menu_display.hpp>
#include <display/player_display.hpp>
#include <display/message_display.hpp>

class Menu;
class GameStatus;

class GameMaster
{
  public:
    GameMaster(std::default_random_engine& rand_engine);
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
    Enemies        enemies;
    std::vector<std::string> messages;
    std::default_random_engine& rand_engine;
};

#endif  // INCLUDED_GAME_MASTER_HPP
