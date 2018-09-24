#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <map/map.hpp>
#include <map/floor.hpp>
#include <map/path.hpp>
#include <map/none.hpp>
#include <map/horizontal_wall.hpp>
#include <map/vertical_wall.hpp>
#include <map/door.hpp>

namespace map
{
  const std::shared_ptr<MapElem> Map::get_elem(const Point& point) const
  {
    return elems[width * point.get_y() + point.get_x()];
  }

  bool Map::in_range(const Point& point) const
  {
    return 0 <= point.get_x() < width && 0 <= point.get_y() < height;
  }
  
  std::shared_ptr<MapElem> gen_map_elem(std::string type)
  {
    if (type == "floor") {
      return std::shared_ptr<Floor>(new Floor{type});
    } else if (type == "path") {
      return std::shared_ptr<Path>(new Path{type});
    } else if (type == "none") {
      return std::shared_ptr<None>(new None{type});
    } else if (type == "horizontal_wall") {
      return std::shared_ptr<HorizontalWall>(new HorizontalWall{type});
    } else if (type == "vertical_wall") {
      return std::shared_ptr<VerticalWall>(new VerticalWall{type});
    } else if (type == "door") {
      return std::shared_ptr<Door>(new Door{type});
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
      std::vector<std::shared_ptr<MapElem> > elems{};
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
        const boost::property_tree::ptree& elem{child.second};
        std::string type = elem.get_optional<std::string>("type").get();
        elems.push_back(gen_map_elem(type));
      }
      map.elems = std::valarray<std::shared_ptr<MapElem> >{elems.data(), elems.size()};
    }
    return map;
  }
}
