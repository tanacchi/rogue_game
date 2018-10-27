#ifndef INCLUDED_ROGUE_GAME_GAME_MASTER_HPP
#define INCLUDED_ROGUE_GAME_GAME_MASTER_HPP

#include <map/point.hpp>
#include <rogue_game/rogue_game.hpp>

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
  void take_dungeon_mode(const KeyboardManager::KeyState& key_state);
  void take_select_mode(const KeyboardManager::KeyState& key_state);
private:
  map::Map map_;
  map::MapDisplay map_display_;
  PlayerDisplay player_display_;
  KeyboardManager keyboard_;
  character::Player player_;
  Mode current_mode_;
};

#endif  // INCLUDED_ROGUE_GAME_GAME_MASTER_HPP
