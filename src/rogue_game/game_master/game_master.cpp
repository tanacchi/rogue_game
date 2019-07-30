#include <exception>

#include <game_master/game_master.hpp>
#include <character/inventory.hpp>
#include <map/map_reader.hpp>
#include <menu/menu.hpp>
#include <utility/path.hpp>
#include <action/any_action.hpp>
#include <action/gold_action.hpp>
#include <action/action_handler.hpp>

GameMaster::GameMaster()
  : map_display{5, 4, 80, 30}
  , player_display{70, 30, 20, 10}
  , message_display{10, 30, 50, 10}
  , keyboard{}
  , player()
{
  MapReader map_reader{};
  map = map_reader(map_dir + "json/tmp_sample_map.json");
  player.set_position(map.initial_position);
}

GameMaster::~GameMaster()
{
  endwin();
}

GameStatus GameMaster::show(const GameStatus& status)
{
  map_display.show(map, player);
  player_display.show(player);
  message_display.show();
  return GameStatus{status.mode, Task::Input};
}

GameStatus GameMaster::input(const GameStatus& status)
{
  keyboard.update();
  return GameStatus{status.mode, Task::Switch};
}

GameStatus GameMaster::toggle_mode(const GameStatus& status)
{
  GameStatus next_status{status.mode, Task::Perform};
  if (keyboard == KeyManager::Space)
    next_status.mode = status.mode == Mode::Dungeon ? Mode::Select : Mode::Dungeon;
  return next_status;
}

GameStatus GameMaster::handle_dungeon(const GameStatus& status)
{
  // Update player's motion
  const auto motion{Player::motion_table.find(keyboard.get()) != Player::motion_table.end() ?
      Player::motion_table.at(keyboard.get()) : zero};
  const auto next_position{player.get_position() + motion};
  if (map.in_range(next_position) && map.get_dungeon_elem(next_position).can_stand())
  {
    player.assign_motion(motion);
  }
  // Get items
  const auto current_position{player.get_position()};
  const auto picked_up_item_itr{map.item_layer.find(current_position)};
  if (picked_up_item_itr != map.item_layer.end())
  {
    player.inventory_ptr->store(std::move(picked_up_item_itr->second));
    map.item_layer.erase(picked_up_item_itr);
  }
  return GameStatus{Mode::Dungeon, Task::Show};
}
