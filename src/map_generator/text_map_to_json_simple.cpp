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

#include <rogue_game.hpp>

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

std::string get_map_text(std::string filename, std::size_t map_width, std::size_t map_height)
{
  std::ifstream read_file{};
  read_file.open(filename, std::ios::in);

  std::stringstream ss{};
  std::string input_buff{};
  for (int row{0}; row < map_height && !read_file.eof(); ++row) {
    std::getline(read_file, input_buff);
    input_buff = (input_buff.length() > map_width) ? input_buff.substr(0, map_width) : input_buff;
    ss << std::setw(map_width) << std::setfill(' ') << std::left << input_buff;
  }
  return ss.str();
}

void write_map_json(std::size_t map_width, std::size_t map_height,
                     std::string map_text,  std::string output_name = "tmp_sample_map")
{
  boost::property_tree::ptree map_data;
  map_data.put("Map.width", map_width);
  map_data.put("Map.height", map_height);
  
  boost::property_tree::ptree elem_list;
  for (std::size_t i{0}, length{map_text.length()}; i < length; ++i) {
    boost::property_tree::ptree elem;
    elem.put("type", map::get_type(map_text[i]));
    elem_list.push_back(std::make_pair("", elem));
  }
  map_data.add_child("Map.elems", elem_list);
  
  boost::property_tree::write_json(std::cout, map_data);
  boost::property_tree::write_json(map_dir+"json/"+output_name+".json", map_data);
}

int main(int argc, char** argv)
{
  try {
    if (argc != 4) {
      throw std::logic_error{"Invalid arguments."};
    }
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    std::size_t map_width{std::stoul(arg_list[2])};
    std::size_t map_height{std::stoul(arg_list[3])};
    std::cout << "File:   [" << text_map_filname << "]" << std::endl;
    std::cout << "Width:  [" << map_width << "]" << std::endl;
    std::cout << "Height: [" << map_height << "]" << std::endl;
    
    std::string map_text{get_map_text(text_map_filname, map_width, map_height)};
    std::cout << "Map text:" << '\n' << map_text << std::endl;

    write_map_json(map_width, map_height, map_text);
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file, argv[2]: width, argv[3]: height" << std::endl;
    return -1;
  }
  return 0;
}
