#include <dungeon/dungeon_series.hpp>
#include <item/item_series.hpp>
#include <map/map_reader.hpp>

DungeonElemPtr gen_dungeon_elem(std::string type)
{
  static std::unordered_map<std::string, std::function<::DungeonElemPtr(void)>> dungeon_table{{
    {"floor",           [](){ return DungeonElemPtr(new Floor{}); }},
    {"path",            [](){ return DungeonElemPtr(new Path{}); }},
    {"none",            [](){ return DungeonElemPtr(new None{}); }},
    {"horizontal_wall", [](){ return DungeonElemPtr(new HorizontalWall{}); }},
    {"vertical_wall",   [](){ return DungeonElemPtr(new VerticalWall{}); }},
    {"door",            [](){ return DungeonElemPtr(new Door{}); }},
  }};
  return dungeon_table.at(type)();
}

ItemPtr gen_item_elem(std::string type, boost::property_tree::ptree property)
{
  static std::unordered_map<std::string, std::function<::ItemPtr(boost::property_tree::ptree)>> item_table{{
    {"gold",
      [](boost::property_tree::ptree property){
        std::size_t amount{property.get_optional<std::size_t>("amount").get()};
        return ItemPtr(new Gold{amount});
      }},
  }};
  return item_table.at(type)(property);
}

Map MapReader::operator()(std::string map_filename)
{
  Map map{};
  boost::property_tree::ptree json_map_data{};
  try
  {
    boost::property_tree::read_json(map_filename, json_map_data);
  }
  catch (boost::property_tree::file_parser_error& e)
  {
    LOG_STRING("=== Couldn't open map file ===");
    LOG_VALUES(e.what());
    auto has_failed{std::system("./map_maker.out ./map/text/sample_map_1.txt")};  // XXX: Make absolute
    if (has_failed)
    {
      LOG_STRING("=== Couldn't make map file ===");
      LOG_VALUES(e.what());
      std::string error_msg{"[ERROR] You should make map\n$ ./map_maker.out map/text/sample_map_1.txt"};
      throw std::runtime_error{error_msg};
    }
    LOG_STRING("=== Map was made automatically ===");
    boost::property_tree::read_json(map_filename, json_map_data);
  }
  {
    map.width = json_map_data.get_optional<int>("Map.width").get();
    map.height = json_map_data.get_optional<int>("Map.height").get();
    auto player_x{json_map_data.get_optional<int>("Map.player_pos_x").get()};
    auto player_y{json_map_data.get_optional<int>("Map.player_pos_y").get()};
    map.initial_position = Point<int>{player_x, player_y};
  }
  for (const auto& child : json_map_data.get_child("Map.elems"))
  {
    const boost::property_tree::ptree& elem{child.second};
    if (!elem.empty())
    {
      std::string type{elem.get_optional<std::string>("type").get()};
      map.dungeon_layer.emplace_back(std::move(gen_dungeon_elem(type)));
    }
  }
  for (const auto& child : json_map_data.get_child("Map.items"))
  {
    const boost::property_tree::ptree& elem{child.second};
    if (!elem.empty())
    {
      std::string type{elem.get_optional<std::string>("type").get()};
      auto pos_x{elem.get_optional<int>("pos_x").get()};
      auto pos_y{elem.get_optional<int>("pos_y").get()};
      map.item_layer.emplace(Point<int>{pos_x, pos_y}, std::move(gen_item_elem(type, elem)));
    }
  }
  return map;
}
