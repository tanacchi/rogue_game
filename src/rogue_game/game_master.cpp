#include <rogue_game/game_master.hpp>

GameMaster::GameMaster()
  : map_{map::read_map(map_dir + "json/tmp_sample_map.json")},
    map_display_{5, 4, map_.width, map_.height},
    player_display_{70, 30, 20, 10},
    keyboard_{},
    player_{map::Point{10, 15}}
{
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::update()
{
  while (true) {
    map_display_.show(map_, player_);
    player_display_.show(player_);
    refresh();
    const KeyboardManager::KeyState key_state{keyboard_.get_key()};
    player_.update(map_, key_state);
  }
}
