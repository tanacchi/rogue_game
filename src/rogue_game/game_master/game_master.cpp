#include <exception>

#include <game_master/game_master.hpp>
#include <map/map_reader.hpp>

GameMaster::GameMaster()
  : map_display_{5, 4, 80, 30},
    player_display_{70, 30, 20, 10},
    menu_display_{100, 10, 30, 16},
    keyboard_{},
    player_()
{
  map::MapReader map_reader{};
  map_ = map_reader(map_dir + "json/tmp_sample_map.json");
  player_.set_position(map_.initial_position);
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::show()
{
  // 画面表示
  map_display_.show(map_, player_);
  player_display_.show(player_);
  menu_display_.show();
  refresh();
}

GameMaster::Mode GameMaster::take_dungeon_mode()
{
  if (keyboard_ == KeyManager::Space)
  {
    return Mode::Select;
  }
  {
    // プレイヤーの位置更新
    map::Point<int> motion{character::Player::motion_table.find(keyboard_.get()) != character::Player::motion_table.end() ?
        character::Player::motion_table.at(keyboard_.get()) : map::Point<int>{0, 0}};
    map::Point<int> next_position{player_.get_position() + motion};
    if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand()) {
      player_.assign_motion(motion);
    }
  }
  {
    // アイテムの取得・更新
    map::Point<int> current_position{player_.get_position()};
    std::map<map::Point<int>, ::item::ItemPtr>::iterator it{map_.item_layer.find(current_position)};
    if (it != map_.item_layer.end()) {
      player_.store_item(std::move(it->second));
      map_.item_layer.erase(it);
    }
  }
  return Mode::Dungeon;
}

GameMaster::Mode GameMaster::take_select_mode()
{
  // アイテムの使用
  menu_display_.set_menu(player_.get_item_name_array());
  if (keyboard_.is_match(KeyManager::Back|KeyManager::Space)) {
    menu_display_.set_visible(false);
    return Mode::Dungeon;
  } else if (keyboard_ == KeyManager::Enter) {
    int item_index{menu_display_.get_current_index()};
    player_.use_item(item_index);
    menu_display_.set_visible(false);
    return Mode::Dungeon;
  } else {
    menu_display_.toggle_menu(keyboard_);
    menu_display_.set_visible(true);
    refresh();
    return Mode::Select;
  }
}

// ゲームの要素全てを更新する
// タスク過多な気がする
void GameMaster::update()
{
  Mode mode{Mode::Dungeon};

  while (true) {
    show();
    keyboard_.update();

    switch (mode) {
    case Mode::Dungeon:
      mode = take_dungeon_mode();
      break;
    case Mode::Select:
      mode = take_select_mode();
      break;
    }
  }
}
