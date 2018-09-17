#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <stdexcept>
#include <vector>
#include <fstream>

int main(int argc, char** argv)
{
  std::string text_map_data{};
  try {
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    std::cout << text_map_filname << std::endl;
    std::ifstream read_file{};
    read_file.open(text_map_filname, std::ios::in);
    std::string input_buff{};
    while (!read_file.eof()) {
      std::getline(read_file, input_buff);
      std::cout << '$' << input_buff << '$' << std::endl;
      text_map_data += input_buff;
    }
  }
  catch (const std::logic_error& e) {
    std::cout << "[Usage]: argv[1]: text_map_file, argv[2]: width, argv[3]: height" << std::endl;
  }
  std::cout << "Map data:" << text_map_data << std::endl;
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
