#include <dungeon/dungeon_series.hpp>
#include <item/item_series.hpp>
#include <map/map_reader.hpp>

// ダンジョン要素からインスタンスを生成しポイントを返す
// オブジェクトファクトリ
::DungeonElemPtr gen_dungeon_elem(std::string type)
{
  static std::unordered_map<std::string, std::function<::DungeonElemPtr(void)>> dungeon_table{{
    {"floor",           [](){ return ::DungeonElemPtr(new ::Floor{}); }},
      {"path",            [](){ return ::DungeonElemPtr(new ::Path{}); }},
      {"none",            [](){ return ::DungeonElemPtr(new ::None{}); }},
      {"horizontal_wall", [](){ return ::DungeonElemPtr(new ::HorizontalWall{}); }},
      {"vertical_wall",   [](){ return ::DungeonElemPtr(new ::VerticalWall{}); }},
      {"door",            [](){ return ::DungeonElemPtr(new ::Door{}); }},
  }};
  return dungeon_table.at(type)();
}

::item::ItemPtr gen_item_elem(std::string type, boost::property_tree::ptree property)
{
  static std::unordered_map<std::string, std::function<::item::ItemPtr(boost::property_tree::ptree)>> item_table{{
    {"gold", [](boost::property_tree::ptree property){
                                                       std::size_t amount{property.get_optional<std::size_t>("amount").get()};
                                                       return ::item::ItemPtr(new ::item::Gold{amount});
                                                     }},
  }};
  return item_table.at(type)(property);
}

Map MapReader::operator()(std::string map_filename)
{
  // json から Map のインスタンスを生成する
  Map map{};
  boost::property_tree::ptree json_map_data{};
  boost::property_tree::read_json(map_filename, json_map_data);
  {
    // マップの横幅を取得
    map.width = json_map_data.get_optional<int>("Map.width").get();

    // マップの縦幅を取得
    map.height = json_map_data.get_optional<int>("Map.height").get();

    // プレイヤーの初期位置を取得
    auto player_x{json_map_data.get_optional<int>("Map.player_pos_x").get()};
    auto player_y{json_map_data.get_optional<int>("Map.player_pos_y").get()};
    map.initial_position = Point<int>{player_x, player_y};
  }

  // ダンジョン要素を取得
  {
    BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems")) {
      const boost::property_tree::ptree& elem{child.second};
      if (!elem.empty()) {
        std::string type{elem.get_optional<std::string>("type").get()};
        map.dungeon_layer.emplace_back(std::move(gen_dungeon_elem(type)));
      }
    }
  }

  // アイテム要素を取得
  {
    BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.items")) {
      const boost::property_tree::ptree& elem{child.second};
      if (!elem.empty()) {
        std::string type{elem.get_optional<std::string>("type").get()};
        auto pos_x{elem.get_optional<int>("pos_x").get()};
        auto pos_y{elem.get_optional<int>("pos_y").get()};
        map.item_layer.emplace(Point<int>{pos_x, pos_y}, std::move(gen_item_elem(type, elem)));
      }
    }
  }
  return map;
}
