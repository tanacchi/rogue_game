#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <ncurses.h>

#include <map.hpp>

namespace map {
  Map read_map(const std::string mapfile_name)
  {
    Map map{};
    boost::property_tree::ptree json_map_data{};
    boost::property_tree::read_json(mapfile_name, json_map_data);
    {
      int width = json_map_data.get_optional<int>("Map.width").get();
      mvprintw(0, 0, "width: [%d]", width);;
      map.width = width;
    }
    {
      int height = json_map_data.get_optional<int>("Map.height").get();
      mvprintw(1, 0, "height: [%d]", height);
      map.height = height;
    }
    {
      std::vector<MapElem> elems{};
      BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
        const boost::property_tree::ptree& elem{child.second};
        std::string type = elem.get_optional<std::string>("type").get();
        elems.push_back(MapElem{type});
      }
      map.elems = std::valarray<MapElem>{elems.data(), elems.size()};
    }
    return map;
  }
}
