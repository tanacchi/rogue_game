#include <rogue_game/game_master.hpp>

GameMaster::GameMaster()
  : map_{map::read_map(map_dir + "json/tmp_sample_map.json")},
    map_display_{5, 4, map_.width, map_.height},
    player_display_{70, 30, 20, 10},
    keyboard_{},
    player_(map_.initial_position)
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
    {
      map::Point motion{character::Player::motion_table.find(key_state) != character::Player::motion_table.end() ?
          character::Player::motion_table.at(key_state) : map::Point{0, 0}};
      map::Point next_position{player_.get_position() + motion};
      if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand()) {
        player_.set_position(next_position);
      }
    }
  }
}
