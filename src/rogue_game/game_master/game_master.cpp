#include <exception>

#include <game_master/game_master.hpp>
#include <map/map_reader.hpp>
#include <menu/menu.hpp>

GameMaster::GameMaster()
  : map_display_{5, 4, 80, 30},
    player_display_{70, 30, 20, 10},
    menu_display_{100, 10, 30, 16},
    keyboard_{},
    player_()
{
  MapReader map_reader{};
  map_ = map_reader(map_dir + "json/tmp_sample_map.json");
  player_.set_position(map_.initial_position);
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::run()
{
  GameStatus status{};

  while (status.task != Task::End)
  {
    switch (status.task)
    {
      case Task::Show:
        status = show(status);
        break;
      case Task::Input:
        status = input(status);
        break;
      case Task::Perform:
        status = perform(status);
        break;
      case Task::End:
        return;
      default:
        LOG_STRING("Unknown task detected.");
        status.task = Task::End;
        break;
    }
  }
}

GameStatus GameMaster::show(const GameStatus& status)
{
  // 画面表示
#ifndef DEBUG
  map_display_.show(map_, player_);
  player_display_.show(player_);
  menu_display_.show();
#endif
  return GameStatus{status.mode, Task::Input};
}

GameStatus GameMaster::input(const GameStatus& status)
{
  keyboard_.update();
  return GameStatus{status.mode, Task::Perform};
}

GameStatus GameMaster::perform(const GameStatus& status)
{
  return status.mode == Mode::Dungeon ? 
    take_dungeon_mode(status) : take_select_mode(status);
}

GameStatus GameMaster::take_dungeon_mode(const GameStatus& status)
{
  if (keyboard_ == KeyManager::Space)
  {
    // target_menu_ptr.reset(new Menu{Menu::base_contents, this});
    // menu_display_.reset_menu(target_menu_ptr);
    return GameStatus{Mode::Select, Task::Show};
  }
  // プレイヤーの位置更新
  const auto motion{Player::motion_table.find(keyboard_.get()) != Player::motion_table.end() ?
      Player::motion_table.at(keyboard_.get()) : zero};
  const auto next_position{player_.get_position() + motion};
  if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand())
  {
    player_.assign_motion(motion);
  }
  // アイテムの取得・更新
  const auto current_position{player_.get_position()};
  const auto picked_up_item_itr{map_.item_layer.find(current_position)};
  if (picked_up_item_itr != map_.item_layer.end())
  {
    player_.store_item(std::move(picked_up_item_itr->second));
    map_.item_layer.erase(picked_up_item_itr);
  }
  return GameStatus{Mode::Dungeon, Task::Show};
}

GameStatus GameMaster::take_select_mode(const GameStatus& status)
{
  if (keyboard_.is_match(KeyManager::Back|KeyManager::Space))
  {
    // target_menu_ptr.reset();
    return GameStatus{Mode::Dungeon, Task::Show};
  }
  else if (keyboard_ == KeyManager::Enter)
  {
    auto selected_content_name{menu_display_.get_selected_content_name()};
    // アイテムの使用
    // auto next_status{target_menu_ptr->execute(selected_content_name, target_menu_ptr)};
    // menu_display_.reset_menu(target_menu_ptr);
    // return next_status;
    return GameStatus{Mode::Dungeon, Task::Show};
  }
  else
  {
    menu_display_.toggle_cursor(keyboard_);
    return GameStatus{Mode::Select, Task::Show};
  }
}
