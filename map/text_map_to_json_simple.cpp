#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>

namespace map
{
  std::string get_type(char elem_char)
  {
    switch (elem_char) {
    case ' ': return "none";
    case '-': return "horizontal_wall";
    case '|': return "vertical_wall";
    case '.': return "floor";
    case '#': return "path";
    }
  }
}

int main(int argc, char** argv)
{
  std::stringstream ss{};
  int map_width{}, map_height{};
  try {
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    map_width = std::stoi(arg_list[2]);
    map_height = std::stoi(arg_list[3]);
    std::cout << text_map_filname << std::endl;
    std::ifstream read_file{};
    read_file.open(text_map_filname, std::ios::in);
    std::string input_buff{};
    for (int row{0}; row < map_height && !read_file.eof(); ++row) {
      std::getline(read_file, input_buff);
      input_buff = (input_buff.length() > map_width) ? input_buff.substr(0, map_width) : input_buff;
      ss << std::setw(map_width) << std::setfill(' ') << std::left << input_buff;
    }
  }
  catch (const std::logic_error& e) {
    std::cout << "[Usage]: argv[1]: text_map_file, argv[2]: width, argv[3]: height" << std::endl;
  }
  std::string map_string{ss.str()};
  std::cout << "Map data:" << '\n' << map_string << std::endl;
  boost::property_tree::ptree map_data;
  map_data.put("Map.width", map_width);
  map_data.put("Map.height", map_height);
  boost::property_tree::ptree elem_list;
  for (int i{0}; i < map_string.length(); ++i) {
    boost::property_tree::ptree elem;
    elem.put("type", map::get_type(map_string[i]));
    elem_list.push_back(std::make_pair("", elem));
  }
  map_data.add_child("Map.elems", elem_list);

  boost::property_tree::write_json("tmp_sample_map.json", map_data);
  return 0;
}
