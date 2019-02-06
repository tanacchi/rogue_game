#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <keyboard/key_manager.hpp>
#include <display/map_display.hpp>
#include <display/player_display.hpp>
#include <map/point.hpp>
#include <rogue_game/rogue_game.hpp>
#include <display/menu_display.hpp>

// ゲームの進行を扱う
class GameMaster
{
public:
  enum class Mode : std::uint8_t
  {
    Dungeon,
    Select
  };
  
  GameMaster();
  ~GameMaster();
  void update();
  void take_dungeon_mode();
  void take_select_mode();
private:
  map::Map map_;
  map::MapDisplay map_display_;
  PlayerDisplay player_display_;
  menu::MenuDisplay menu_display_;
  KeyManager keyboard_;
  character::Player player_;
  Mode current_mode_;
};

#endif  // INCLUDED_GAME_MASTER_HPP
