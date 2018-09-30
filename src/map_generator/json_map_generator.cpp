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
#include <map>
#include <functional>

#include <rogue_game.hpp>
#include <map/text_map.hpp>
#include <map/map_generator.hpp>

namespace map
{
  namespace generator
  {
    std::vector<std::string> read_map_strings(std::string filename)
    {
      std::ifstream read_file{};
      read_file.open(filename, std::ios::in);

      std::vector<std::string> map_strings{};
      std::string input_buff{};
      for (std::size_t row{0}; !read_file.eof(); ++row) {
        std::getline(read_file, input_buff);
        map_strings.emplace_back(input_buff);
      }
      return map_strings;
    }

    TextMap get_text_map_obj(std::vector<std::string> map_strings)
    {
      TextMap tm;
      for (auto row : map_strings) {
        tm.width = std::max(tm.width, row.length());
      }
      tm.height = map_strings.size();
      std::stringstream ss{};
      for (auto row : map_strings) {
        ss << std::setw(tm.width) << std::setfill(' ') << std::left << row;
      }
      tm.text = ss.str();
      return tm;
    }
  }
}

int main(int argc, char** argv)
{
  try {
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    std::vector<std::string> map_strings{map::generator::read_map_strings(text_map_filname)};
    map::TextMap text_map{map::generator::get_text_map_obj(map_strings)};
    text_map.show();
    map::generator::MapGenerator map_generator{text_map};
    map_generator.set_elem_config_table();
    map_generator.set_configs();
    map_generator.write_json_map();
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
