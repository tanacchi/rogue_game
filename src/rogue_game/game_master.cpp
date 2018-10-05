#include <rogue_game/game_master.hpp>

GameMaster::GameMaster()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::update()
{
  map::Map map = map::read_map(map_dir + "json/tmp_sample_map.json");
  map::MapDisplay md{5, 4, map.width, map.height};
  PlayerDisplay   pd{70, 30, 20, 10};
  // std::unique_ptr<KeyboardManager> km_ptr{new KeyboardManager};
  character::Player player{map::Point{10, 15}};
  while (true) {
    md.show(map, player);
    pd.show(player);
    refresh();
    // player.update(map);
  }
}
