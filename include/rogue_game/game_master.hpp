#ifndef INCLUDED_ROGUE_GAME_GAME_MASTER_HPP
#define INCLUDED_ROGUE_GAME_GAME_MASTER_HPP

#include <map/point.hpp>
#include <rogue_game/rogue_game.hpp>

// ゲームの進行を扱う
class GameMaster
{
public:
  GameMaster();
  ~GameMaster();
  void update();
private:
  map::Map map_;
  map::MapDisplay map_display_;
  PlayerDisplay player_display_;
  KeyboardManager keyboard_;
  character::Player player_;
};

#endif  // INCLUDED_ROGUE_GAME_GAME_MASTER_HPP
