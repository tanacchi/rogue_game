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
  const std::shared_ptr<::dungeon::DungeonElem> Map::get_dungeon_elem(const Point& point) const
  {
    return dungeon_layer[width * point.get_y() + point.get_x()];
  }

  bool Map::in_range(const Point& point) const
  {
    return 0 <= point.get_x() && point.get_x() < width && 0 <= point.get_y() && point.get_y() < height;
  }

  Point Map::index_to_point(std::size_t index)
  {
    int x{static_cast<int>(index % height)};
    int y{static_cast<int>(index / height)};
    return Point{x, y};
  }
  
  std::shared_ptr<::dungeon::DungeonElem> gen_map_elem(std::string type)
  {
    if (type == "floor") {
      return std::shared_ptr<::dungeon::Floor>(new ::dungeon::Floor{});
    } else if (type == "path") {
      return std::shared_ptr<::dungeon::Path>(new ::dungeon::Path{});
    } else if (type == "none") {
      return std::shared_ptr<::dungeon::None>(new ::dungeon::None{});
    } else if (type == "horizontal_wall") {
      return std::shared_ptr<::dungeon::HorizontalWall>(new ::dungeon::HorizontalWall{});
    } else if (type == "vertical_wall") {
      return std::shared_ptr<::dungeon::VerticalWall>(new ::dungeon::VerticalWall{});
    } else if (type == "door") {
      return std::shared_ptr<::dungeon::Door>(new ::dungeon::Door{});
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
      std::vector<std::shared_ptr<::dungeon::DungeonElem> > elems{};
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
        const boost::property_tree::ptree& elem{child.second};
        std::string type = elem.get_optional<std::string>("type").get();
        elems.push_back(gen_map_elem(type));
      }
      map.dungeon_layer = std::valarray<std::shared_ptr<::dungeon::DungeonElem> >{elems.data(), elems.size()};
    }
    {
      std::vector<std::shared_ptr<::item::Item> > elems{};
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.items") ) {
        const boost::property_tree::ptree& elem{child.second};
        std::size_t index = elem.get_optional<std::size_t>("index").get();
        Point pos{map.index_to_point(index)};
        std::string type{elem.get_optional<std::string>("type").get()};
        std::size_t amount{elem.get_optional<std::size_t>("amount").get()};
        elems.push_back(std::shared_ptr<::item::Gold>{new ::item::Gold{pos, amount}});
      }
      map.item_layer = std::valarray<std::shared_ptr<::item::Item> >{elems.data(), elems.size()};
    }
    return map;
  }
}
