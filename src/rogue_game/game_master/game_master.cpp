#include <exception>

#include <game_master/game_master.hpp>
#include <map/map_reader.hpp>
#include <menu/menu.hpp>

GameMaster::GameMaster()
  : map_display{5, 4, 80, 30},
    player_display{70, 30, 20, 10},
    menu_display{100, 10, 30, 16},
    keyboard{},
    player()
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
  // 画面表示
#ifndef DEBUG
  map_display.show(map, player);
  player_display.show(player);
  // menu_display.show(Menu{});
#endif
  return GameStatus{status.mode, Task::Input};
}

GameStatus GameMaster::input(const GameStatus& status)
{
  keyboard.update();
  return GameStatus{status.mode, Task::Perform};
}

GameStatus GameMaster::perform(const GameStatus& status)
{
  return status.mode == Mode::Dungeon ? 
    take_dungeon_mode(status) : take_select_mode(status);
}

GameStatus GameMaster::take_dungeon_mode(const GameStatus& status)
{
  if (keyboard == KeyManager::Space)
  {
    // target_menu_ptr.reset(new Menu{Menu::base_contents, this});
    return GameStatus{Mode::Select, Task::Show};
  }
  // プレイヤーの位置更新
  const auto motion{Player::motion_table.find(keyboard.get()) != Player::motion_table.end() ?
      Player::motion_table.at(keyboard.get()) : zero};
  const auto next_position{player.get_position() + motion};
  if (map.in_range(next_position) && map.get_dungeon_elem(next_position).can_stand())
  {
    player.assign_motion(motion);
  }
  // アイテムの取得・更新
  const auto current_position{player.get_position()};
  const auto picked_up_item_itr{map.item_layer.find(current_position)};
  if (picked_up_item_itr != map.item_layer.end())
  {
    player.store_item(std::move(picked_up_item_itr->second));
    map.item_layer.erase(picked_up_item_itr);
  }
  return GameStatus{Mode::Dungeon, Task::Show};
}

GameStatus GameMaster::take_select_mode(const GameStatus& status)
{
  if (keyboard.is_match(KeyManager::Back|KeyManager::Space))
  {
    // target_menu_ptr.reset();
    return GameStatus{Mode::Dungeon, Task::Show};
  }
  else if (keyboard == KeyManager::Enter)
  {
    // アイテムの使用
    return GameStatus{Mode::Dungeon, Task::Show};
  }
  else
  {
    return GameStatus{Mode::Select, Task::Show};
  }
}
