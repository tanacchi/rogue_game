#include <rogue_game/game_master.hpp>
#include <display/menu_display.hpp>

GameMaster::GameMaster()
  : map_{map::read_map(map_dir + "json/ver_0.1.0.0_map.json")},
    map_display_{5, 4, map_.width, map_.height},
    player_display_{70, 30, 20, 10},
    keyboard_{},
    player_(map_.initial_position)
{
  debug::Logger::log_string("game master initialized");
}

GameMaster::~GameMaster()
{
  endwin();
}

// ゲームの要素全てを更新する
// タスク過多な気がする
void GameMaster::update()
{
  // 画面表示
  map_display_.show(map_, player_);
  player_display_.show(player_);
  refresh();

  static menu::MenuDisplay menu_display{80, 10, 30, 15};

  // キーボード入力は外に出して
  // Unknown なら sleep ｗｐ挟むとかしたいけど
  // ncurses の知識がもう少しいるので後回し
  const KeyboardManager::KeyState key_state{keyboard_.get_key()};
  {
    // プレイヤーの位置更新
    map::Point motion{character::Player::motion_table.find(key_state) != character::Player::motion_table.end() ?
        character::Player::motion_table.at(key_state) : map::Point{0, 0}};
    map::Point next_position{player_.get_position() + motion};
    if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand()) {
      player_.set_position(next_position);
    }
  }
  {
    // アイテムの取得・更新
    map::Point current_position{player_.get_position()};
    std::map<map::Point, std::unique_ptr<::item::Item> >::iterator it{map_.item_layer.find(current_position)};
    if (it != map_.item_layer.end()) {
      player_.store_item(std::move(it->second));
      map_.item_layer.erase(it);
      menu_display.set_menu(player_.get_item_name_array());
      menu_display.show();
    }
  }
  {
    // アイテムの使用（テスト）
    if (key_state == KeyboardManager::KeyState::Space) {
      player_.use_item(0);
      menu_display.set_menu(player_.get_item_name_array());
      menu_display.show();
    }
  }
}
