#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <vector>

#include <ncurses.h>

#include <map.hpp>

char converter(std::string type)
{
  if (type == "horizontal_wall") return '-';
  if (type == "vertical_wall") return '|';
  if (type == "floor") return '.';
  if (type == "path") return '#';
  if (type == "none") return ' ';
}

void read_map(const std::string mapfile_name)
{
  boost::property_tree::ptree json_map_data{};
  boost::property_tree::read_json(mapfile_name, json_map_data);
  int width = json_map_data.get_optional<int>("Map.width").get();
  std::cout << "width: " << width << "."<< std::endl;
  int height = json_map_data.get_optional<int>("Map.height").get();
  std::cout << "height: " << height << "."<< std::endl;
  std::vector<std::vector<std::string> > elems{height};
  int count{0};
  BOOST_FOREACH (const boost::property_tree::ptree::value_type& child, json_map_data.get_child("Map.elems") ) {
    const boost::property_tree::ptree& elem{child.second};
    std::string type = elem.get_optional<std::string>("type").get();
    elems[static_cast<int>(count++/width)].push_back(type);
  }
  for (int y = 0; y < elems.size(); y++) {
    for (int x = 0; x < elems[0].size(); ++x) {
      mvprintw(y, x, "%c",converter(elems[y][x]));
    }
  }
}
