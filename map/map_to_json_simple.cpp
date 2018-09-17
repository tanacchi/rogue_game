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

int main(int argc, char** argv)
{
  std::stringstream ss{};
  try {
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    int map_width{std::stoi(arg_list[2])};
    int map_height{std::stoi(arg_list[3])};
    std::cout << text_map_filname << std::endl;
    std::ifstream read_file{};
    read_file.open(text_map_filname, std::ios::in);
    std::string input_buff{};
    for (int row{0}; row < map_height && !read_file.eof(); ++row) {
      std::getline(read_file, input_buff);
      input_buff = (input_buff.length() > map_width) ? input_buff.substr(0, map_width) : input_buff;
      ss << '$' << std::setw(map_width) << std::setfill(' ') << std::left << input_buff << '$' << '\n';
    }
  }
  catch (const std::logic_error& e) {
    std::cout << "[Usage]: argv[1]: text_map_file, argv[2]: width, argv[3]: height" << std::endl;
    return 1;
  }
  std::cout << "Map data:" << '\n' << ss.str() << std::endl;
  return 0;
  boost::property_tree::ptree map_data;
  map_data.put("Map.width", 30);
  map_data.put("Map.height", 10);
  boost::property_tree::ptree elem_list;
  for (int i{0}; i < 3; ++i) {
    boost::property_tree::ptree elem;
    elem.put("type", "horizontal_wall");
    elem_list.push_back(std::make_pair("", elem));
  }
  map_data.add_child("Map.elems", elem_list);

  boost::property_tree::write_json("tmp_sample_map.json", map_data);
  return 0;
}