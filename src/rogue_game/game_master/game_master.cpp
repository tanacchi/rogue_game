#include <exception>

#include <rogue_game/game_master.hpp>

GameMaster::GameMaster()
  : map_{map::read_map(map_dir + "json/ver_0.1.0.0_map.json")},
    map_display_{5, 4, map_.width, map_.height},
    player_display_{70, 30, 20, 10},
    menu_display_{80, 10, 30, 16},
    keyboard_{},
    player_(map_.initial_position),
    current_mode_{Mode::Dungeon}
{
}

GameMaster::~GameMaster()
{
  endwin();
}

void GameMaster::take_dungeon_mode(const KeyboardManager::KeyState& key_state)
{
  {
    // プレイヤーの位置更新
    map::Point<int> motion{character::Player::motion_table.find(key_state) != character::Player::motion_table.end() ?
        character::Player::motion_table.at(key_state) : map::Point<int>{0, 0}};
    map::Point<int> next_position{player_.get_position() + motion};
    if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand()) {
      player_.set_position(next_position);
    }
  }
  {
    // アイテムの取得・更新
    map::Point<int> current_position{player_.get_position()};
    std::map<map::Point<int>, std::unique_ptr<::item::Item> >::iterator it{map_.item_layer.find(current_position)};
    if (it != map_.item_layer.end()) {
      player_.store_item(std::move(it->second));
      map_.item_layer.erase(it);
    }
  }
}

void GameMaster::take_select_mode(const KeyboardManager::KeyState& key_state)
{
  // アイテムの使用
  menu_display_.set_menu(player_.get_item_name_array());
  menu_display_.show();
  for (;;) {                // REFACTOR REQUIRED : 読む気失せる程度に汚いけど動く
    const KeyboardManager::KeyState memu_toggler{keyboard_.get_key()};
    if (memu_toggler == KeyboardManager::KeyState::Back || memu_toggler == KeyboardManager::KeyState::Space) {
      menu_display_.hide();
      break;
    } else if (memu_toggler == KeyboardManager::KeyState::Enter) {
      int item_index{menu_display_.get_current_index()};
      player_.use_item(item_index);
      menu_display_.hide();
      break;
    } else {
      menu_display_.toggle_menu(memu_toggler);
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

  const KeyboardManager::KeyState key_state{keyboard_.get_key()};
  switch (key_state) {
  case KeyboardManager::KeyState::Space:
    current_mode_ = Mode::Select;
    break;
  case KeyboardManager::KeyState::Back:
  case KeyboardManager::KeyState::Enter:
    current_mode_ = Mode::Dungeon;
    break;
  default:
    break;
  }

  switch (current_mode_) {
  case Mode::Dungeon:
    take_dungeon_mode(key_state);
    break;
  case Mode::Select:
    take_select_mode(key_state);
    break;
  }
}
