#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

#include <map_display.hpp>

MapDisplay::MapDisplay(std::size_t x, std::size_t y,
                       std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MapDisplay::read_map(const std::string mapfile_name)
{
  boost::property_tree::ptree json_map_data{};
  boost::property_tree::read_json(mapfile_name, json_map_data);
  int width = json_map_data.get_optional<int>("Map.width").get();
  std::cout << "width: " << width << "."<< std::endl;
  int height = json_map_data.get_optional<int>("Map.height").get();
  std::cout << "height: " << height << "."<< std::endl;
  BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
    const boost::property_tree::ptree& elem{child.second};
    std::string type = elem.get_optional<std::string>("type").get();
    std::cout << "  type: " << type << std::endl;
  }
}
