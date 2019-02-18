#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <display/map_display.hpp>
#include <display/menu_display.hpp>
#include <display/player_display.hpp>
#include <keyboard/key_manager.hpp>
#include <map/point.hpp>

class Menu;

// ゲームの進行を扱う
class GameMaster
{
public:
  enum class Task : std::uint8_t;

  enum class Mode : std::uint8_t
  {
    Dungeon,
    Select
  };
  
  GameMaster();
  ~GameMaster();
  void run();
private:
  void show();
  Mode take_dungeon_mode();
  Mode take_select_mode();

  map::Map          map_;
  map::MapDisplay   map_display_;
  PlayerDisplay     player_display_;
  menu::MenuDisplay menu_display_;
  KeyManager        keyboard_;
  character::Player player_;
};

#endif  // INCLUDED_GAME_MASTER_HPP
