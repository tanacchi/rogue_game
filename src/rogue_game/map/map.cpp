#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <map/map.hpp>
#include <map/floor.hpp>
#include <map/path.hpp>

namespace map
{
  std::shared_ptr<MapElem> gen_map_elem(std::string type)
  {
    if (type == "floor") {
      return std::shared_ptr<Floor>(new Floor{type});
    } else if (type == "path") {
      return std::shared_ptr<Path>(new Path{type});
    } else {
      return std::shared_ptr<MapElem>(new MapElem{type});
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
