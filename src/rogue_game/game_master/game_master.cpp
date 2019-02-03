#include <exception>

#include <rogue_game/game_master.hpp>
#include <map/map_reader.hpp>

GameMaster::GameMaster()
  : map_display_{5, 4, 80, 30},
    player_display_{70, 30, 20, 10},
    menu_display_{80, 10, 30, 16},
    keyboard_{},
    player_(),
    current_mode_{Mode::Dungeon}
{
  map::MapReader map_reader{};
  map_ = std::move(map_reader(map_dir + "json/tmp_sample_map.json"));
  player_.set_position(map_.initial_position);
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::take_dungeon_mode(const KeyManager& key_state)
{
  {
    // プレイヤーの位置更新
    map::Point<int> motion{character::Player::motion_table.find(key_state.get()) != character::Player::motion_table.end() ?
        character::Player::motion_table.at(key_state.get()) : map::Point<int>{0, 0}};
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
}

void GameMaster::take_select_mode(const KeyManager& key_state)
{
  // アイテムの使用
  menu_display_.set_menu(player_.get_item_name_array());
  menu_display_.show();
  for (;;) {                // REFACTOR REQUIRED : 読む気失せる程度に汚いけど動く
    keyboard_.update();
    const KeyManager::KeyType menu_toggler{keyboard_.get()};
    if (keyboard_.is_match(KeyManager::Back|KeyManager::Space)) {
      menu_display_.hide();
      break;
    } else if (keyboard_ == KeyManager::Enter) {
      int item_index{menu_display_.get_current_index()};
      player_.use_item(item_index);
      menu_display_.hide();
      break;
    } else {
      menu_display_.toggle_menu(menu_toggler);
      menu_display_.show();
    }
  }
  current_mode_ = Mode::Dungeon;
}

// ゲームの要素全てを更新する
// タスク過多な気がする
void GameMaster::update()
{
  // 画面表示
  map_display_.show(map_, player_);
  player_display_.show(player_);
  refresh();
  keyboard_.update();

  if (keyboard_ == KeyManager::Space) {
    current_mode_ = Mode::Select;
  } else if (keyboard_.is_match(KeyManager::Back|KeyManager::Enter)) {
    current_mode_ = Mode::Dungeon;
  }

  switch (current_mode_) {
  case Mode::Dungeon:
    take_dungeon_mode(keyboard_);
    break;
  case Mode::Select:
    take_select_mode(keyboard_);
    break;
  }
}
