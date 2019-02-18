#include <exception>

#include <game_master/game_master.hpp>
#include <map/map_reader.hpp>
#include <menu/menu.hpp>

GameMaster::GameMaster()
  : map_display_{5, 4, 80, 30},
    player_display_{70, 30, 20, 10},
    menu_display_{100, 10, 30, 16},
    keyboard_{},
    player_(),
    target_menu_ptr()
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
}

GameMaster::Mode GameMaster::take_dungeon_mode()
{
  if (keyboard_ == KeyManager::Space)
  {
    target_menu_ptr.reset(new Menu{Menu::base_contents});
    menu_display_.set_menu_ptr(target_menu_ptr);
    return Mode::Select;
  }
  // プレイヤーの位置更新
  const auto motion{character::Player::motion_table.find(keyboard_.get()) != character::Player::motion_table.end() ?
      character::Player::motion_table.at(keyboard_.get()) : map::zero};
  const auto next_position{player_.get_position() + motion};
  if (map_.in_range(next_position) && map_.get_dungeon_elem(next_position).can_stand()) {
    player_.assign_motion(motion);
  }
  // アイテムの取得・更新
  const auto current_position{player_.get_position()};
  const auto picked_up_item_itr{map_.item_layer.find(current_position)};
  if (picked_up_item_itr != map_.item_layer.end()) {
    player_.store_item(std::move(picked_up_item_itr->second));
    map_.item_layer.erase(picked_up_item_itr);
  }
  return Mode::Dungeon;
}

GameMaster::Mode GameMaster::take_select_mode()
{
  if (keyboard_.is_match(KeyManager::Back|KeyManager::Space)) {
    target_menu_ptr.reset();
    return Mode::Dungeon;
  } else if (keyboard_ == KeyManager::Enter) {
  // アイテムの使用
    return Mode::Dungeon;
  } else {
    return Mode::Select;
  }
}

void GameMaster::run()
{
  Mode mode{Mode::Dungeon};

  while (true) {
    show();
    keyboard_.update();
    mode = mode == Mode::Dungeon ? take_dungeon_mode() : take_select_mode();
  }
}
