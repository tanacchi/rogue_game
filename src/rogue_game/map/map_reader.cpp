#include <map/map_reader.hpp>
#include <dungeon/dungeon_series.hpp>
#include <item/item_series.hpp>

namespace map
{
  // ダンジョン要素からインスタンスを生成しポイントを返す
  // オブジェクトファクトリ
  ::dungeon::DungeonElemPtr gen_dungeon_elem(std::string type)
  {
    static std::unordered_map<std::string, std::function<::dungeon::DungeonElemPtr(void)>> dungeon_table{{
      {"floor",           [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::Floor{}); }},
      {"path",            [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::Path{}); }},
      {"none",            [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::None{}); }},
      {"horizontal_wall", [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::HorizontalWall{}); }},
      {"vertical_wall",   [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::VerticalWall{}); }},
      {"door",            [](){ return ::dungeon::DungeonElemPtr(new ::dungeon::Door{}); }},
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
      std::size_t player_index{json_map_data.get_optional<std::size_t>("Map.player_pos").get()};
      map.initial_position = map.index_to_point(player_index);
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
          std::size_t index{elem.get_optional<std::size_t>("index").get()};
          Point<int> pos{map.index_to_point(index)};
          map.item_layer.emplace(pos, std::move(gen_item_elem(type, elem)));
        }
      }
    }
    return map;
  }
};
