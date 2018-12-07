#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <map/map.hpp>
#include <dungeon/floor.hpp>
#include <dungeon/path.hpp>
#include <dungeon/none.hpp>
#include <dungeon/horizontal_wall.hpp>
#include <dungeon/vertical_wall.hpp>
#include <dungeon/door.hpp>

#include <item/gold.hpp>

namespace map
{
  Map::Map(Map&& map)
    : width{map.width},
      height{map.height},
      initial_position{std::move(map.initial_position)},
      dungeon_layer{std::move(map.dungeon_layer)},
      item_layer{std::move(map.item_layer)}
  {
  }

  std::ostream& operator<<(std::ostream& os, const Map& map)
  {
    os << "{ width : " << map.width << " }, { height : " << map.height << "},\n"
       << "{ initial_position : " << map.initial_position << " },\n "
       << "{ dungeon_layer :\n";
    for (std::size_t y{0}; y < map.height; ++y, os.put('\n')) {
      for (std::size_t x{0}; x < map.width; ++x) {
        os << map.get_dungeon_elem(map::Point<int>{x, y}).symbol;
      }
    }
    return os;
  }

  // いまのところダンジョン要素の配列を一次元にしているメリットが
  // json からの読み込み位なので
  // そのを解消して二次元に切り替えて見ようかと思う
  const ::dungeon::DungeonElem Map::get_dungeon_elem(const Point<int>& point) const
  {
    const ::dungeon::DungeonElem* elem{dungeon_layer[width * point.get_y() + point.get_x()].get()};
    return *elem;
  }

  bool Map::in_range(const Point<std::size_t>& point) const
  {
    std::size_t x{point.get_x()}, y{point.get_y()};
    return (0 <= x && x < width) && (0 <= y && y < height);
  }

  Point<int> Map::index_to_point(std::size_t index)
  {
    return {index % width, index / width};
  }

  // ダンジョン要素からインスタンスを生成しポイントを返す
  // オブジェクト・ファクトリ
  // TO DO : もうすこしキレイにしたい
  ::dungeon::DungeonElemPtr gen_dungeon_elem(std::string type)
  {
    if (type == "floor") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::Floor{});
    } else if (type == "path") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::Path{});
    } else if (type == "none") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::None{});
    } else if (type == "horizontal_wall") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::HorizontalWall{});
    } else if (type == "vertical_wall") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::VerticalWall{});
    } else if (type == "door") {
      return ::dungeon::DungeonElemPtr(new ::dungeon::Door{});
    } else {
      throw std::string{"Invalid map elem type."};
    }
  }

  // json から Map のインスタンスを生成する
  // コンストラクタに変える予定
  // 要素ごとに取得する変数とかが変わってくるから
  // マクロやらテンプレートでキレイにできたらいいなと思っている
  Map read_map(const std::string mapfile_name)
  {
    Map map{};
    boost::property_tree::ptree json_map_data{};
    boost::property_tree::read_json(mapfile_name, json_map_data);
    // マップの横幅を取得
    {
      map.width = json_map_data.get_optional<int>("Map.width").get();
    }
    // マップの縦幅を取得
    {
      map.height = json_map_data.get_optional<int>("Map.height").get();
    }
    // プレイヤーの初期位置を取得
    {
      std::size_t player_index = json_map_data.get_optional<std::size_t>("Map.player_pos").get();
      map.initial_position = map.index_to_point(player_index);
    }
    // ダンジョン要素を取得
    {
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
        const boost::property_tree::ptree& elem{child.second};
        if (elem.empty()) {
          continue;
        }
        std::string type = elem.get_optional<std::string>("type").get();
        map.dungeon_layer.emplace_back(std::move(gen_dungeon_elem(type)));
      }
    }
    // アイテム要素を取得
    {
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.items") ) {
        const boost::property_tree::ptree& elem{child.second};
        if (elem.empty()) {
          continue;
        }
        std::size_t index = elem.get_optional<std::size_t>("index").get();
        Point<int> pos{map.index_to_point(index)};
        std::string type{elem.get_optional<std::string>("type").get()};
        std::size_t amount{elem.get_optional<std::size_t>("amount").get()};
        map.item_layer.emplace(pos, ::item::ItemPtr{new ::item::Gold{amount}});
      }
    }
    return map;
  }
}
