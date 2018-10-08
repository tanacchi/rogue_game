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
  
  const ::dungeon::DungeonElem Map::get_dungeon_elem(const Point& point) const
  {
    const ::dungeon::DungeonElem* elem{dungeon_layer[width * point.get_y() + point.get_x()].get()};
    return *elem;
  }

  bool Map::in_range(const Point& point) const
  {
    int x{point.get_x()}, y{point.get_y()};
    return (0 <= x && x < static_cast<int>(width)) && (0 <= y && y < static_cast<int>(height));
  }

  Point Map::index_to_point(std::size_t index)
  {
    int x{static_cast<int>(index % width)};
    int y{static_cast<int>(index / width)};
    return {x, y};
  }
  
  std::unique_ptr<::dungeon::DungeonElem> gen_dungeon_elem(std::string type)
  {
    if (type == "floor") {
      return std::unique_ptr<::dungeon::Floor>(new ::dungeon::Floor{});
    } else if (type == "path") {
      return std::unique_ptr<::dungeon::Path>(new ::dungeon::Path{});
    } else if (type == "none") {
      return std::unique_ptr<::dungeon::None>(new ::dungeon::None{});
    } else if (type == "horizontal_wall") {
      return std::unique_ptr<::dungeon::HorizontalWall>(new ::dungeon::HorizontalWall{});
    } else if (type == "vertical_wall") {
      return std::unique_ptr<::dungeon::VerticalWall>(new ::dungeon::VerticalWall{});
    } else if (type == "door") {
      return std::unique_ptr<::dungeon::Door>(new ::dungeon::Door{});
    } else {
      throw std::string{"Invalid map elem type."};
    }
  }
  
  Map read_map(const std::string mapfile_name)
  {
    Map map{};
    boost::property_tree::ptree json_map_data{};
    boost::property_tree::read_json(mapfile_name, json_map_data);
    {
      int width = json_map_data.get_optional<int>("Map.width").get();
      map.width = width;
    }
    {
      int height = json_map_data.get_optional<int>("Map.height").get();
      map.height = height;
    }
    {
      std::size_t player_index = json_map_data.get_optional<std::size_t>("Map.player_pos").get();
      map.initial_position = map.index_to_point(player_index);
    }
    {
      std::vector<std::unique_ptr<::dungeon::DungeonElem> > elems{};
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
        const boost::property_tree::ptree& elem{child.second};
        if (elem.empty()) {
          continue;
        }
        std::string type = elem.get_optional<std::string>("type").get();
        elems.push_back(std::move(gen_dungeon_elem(type)));
      }
      map.dungeon_layer = std::move(elems);
    }
    {
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.items") ) {
        const boost::property_tree::ptree& elem{child.second};
        if (elem.empty()) {
          continue;
        }
        std::size_t index = elem.get_optional<std::size_t>("index").get();
        Point pos{map.index_to_point(index)};
        std::string type{elem.get_optional<std::string>("type").get()};
        std::size_t amount{elem.get_optional<std::size_t>("amount").get()};
        map.item_layer.push_back(std::unique_ptr<::item::Gold>{new ::item::Gold{pos, amount}});
      }
    }
    return map;
  }
}
