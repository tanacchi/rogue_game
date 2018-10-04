#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

int main()
{
  GameMaster master{};
  
  map::Map map = map::read_map(map_dir + "json/tmp_sample_map.json");
  map::MapDisplay md{5, 4, map.width, map.height};
  PlayerDisplay   pd{70, 30, 20, 10};
  std::unique_ptr<KeyboardManager> km_ptr{new KeyboardManager};
  character::Player player{map::Point{10, 15}, std::move(km_ptr)};
  while (true) {
    md.show(map, player);
    pd.show(player);
    refresh();
    player.update(map);
  }
  return 0;
}
