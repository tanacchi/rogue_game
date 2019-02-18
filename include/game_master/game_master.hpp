#ifndef INCLUDED_GAME_MASTER_HPP
#define INCLUDED_GAME_MASTER_HPP

#include <display/map_display.hpp>
#include <display/new_menu_display.hpp>
#include <display/player_display.hpp>
#include <keyboard/key_manager.hpp>
#include <map/point.hpp>
#include <game_master/task.hpp>

class Menu;

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
  void run();
private:
  void show();
  Mode take_dungeon_mode();
  Mode take_select_mode();

  map::Map          map_;
  map::MapDisplay   map_display_;
  PlayerDisplay     player_display_;
  NewMenuDisplay new_menu_display_;
  KeyManager        keyboard_;
  character::Player player_;
  std::unique_ptr<Menu> target_menu_ptr;
};

#endif  // INCLUDED_GAME_MASTER_HPP
