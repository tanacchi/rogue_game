#include <exception>

#include <utility/point.hpp>
#include <game_master/game_status.hpp>
#include <keyboard/key_manager.hpp>
#include <game_master/game_master.hpp>
#include <character/inventory.hpp>
#include <map/map_reader.hpp>
#include <menu/menu.hpp>
#include <utility/path.hpp>
#include <action/any_action.hpp>
#include <action/gold_action.hpp>
#include <action/action_handler.hpp>
#include <action/message_action.hpp>

GameMaster::GameMaster()
  : map_display{5, 4, 80, 30}
  , player_display{70, 30, 20, 10}
  , message_display{10, 30, 50, 10}
  , player()
  , messages{}
{
  MapReader map_reader{};
  map = map_reader(map_dir + "json/tmp_sample_map.json");
  player.set_position(map.initial_position);
  map.make_apparent(player.get_position());
}

GameMaster::~GameMaster()
{
  endwin();
}

GameStatus GameMaster::show(const GameStatus& status)
{
  map_display.show(map, player);
  player_display.show(player);
  message_display.show(messages);
  messages.clear();
  return GameStatus{Task::Input, status.mode};
}

GameStatus GameMaster::input(const GameStatus& status)
{
  KeyManager::update();
  return GameStatus{Task::Perform, status.mode};
}

GameStatus GameMaster::handle_dungeon(const GameStatus& status)
{
  // Switch to Select mode
  if (KeyManager::get() == KeyManager::Space)
  {
    KeyManager::set_key(KeyManager::Null);
    return GameStatus{Task::Perform, Mode::Select};
  }

  // Update player's motion
  const auto motion{Player::motion_table.find(KeyManager::get()) != Player::motion_table.end() ?
      Player::motion_table.at(KeyManager::get()) : zero};
  const auto next_position{player.get_position() + motion};
  if (map.in_range(next_position) && map.get_dungeon_elem(next_position).can_stand())
  {
    player.assign_motion(motion);
    map.make_apparent(player.get_position());
  }
  // Get items
  const auto current_position{player.get_position()};
  const auto picked_up_item_itr{map.item_layer.find(current_position)};
  if (picked_up_item_itr != map.item_layer.end())
  {
    ActionHandler::push(MessageAction<NormalTag>("You got an item !"));
    player.inventory_ptr->store(std::move(picked_up_item_itr->second));
    map.item_layer.erase(picked_up_item_itr);
  }
  return GameStatus{Task::Act, Mode::Dungeon};
}
