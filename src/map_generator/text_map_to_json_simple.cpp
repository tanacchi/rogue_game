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

#include <rogue_game.hpp>

namespace map
{
  namespace generator
  {
    struct TextMap {
      std::size_t width{};
      std::size_t height{};
      std::string text{};
      void show()
      {
        std::cout << "width:  [" << width  << "]\n"
                  << "height: [" << height << "]\n"
                  << "text: " << std::endl;
        for (std::size_t i{0}; i < text.length(); i += width) {
          std::string row{text.substr(i, width)};
          std::cout << row << std::endl;
        }
      }
    };
    
    std::string get_type(char elem_char)
    {
      static std::map<char, std::string> type_table = {
        {' ', "none"},
        {'-', "horizontal_wall"},
        {'|', "vertical_wall"},
        {'.', "floor"},
        {'#', "path"},
        {'+', "door"},
      };
      return type_table.at(elem_char);
    }
  
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
    
    void write_map_json(const TextMap& text_map,  std::string output_name = "tmp_sample_map")
    {
      boost::property_tree::ptree map_data;
      map_data.put("Map.width", text_map.width);
      map_data.put("Map.height", text_map.height);
  
      boost::property_tree::ptree elem_list;
      for (std::size_t i{0}, length{text_map.text.length()}; i < length; ++i) {
        boost::property_tree::ptree elem;
        elem.put("type", get_type(text_map.text[i]));
        elem_list.push_back(std::make_pair("", elem));
      }
      map_data.add_child("Map.elems", elem_list);
  
      boost::property_tree::write_json(map_dir+"json/"+output_name+".json", map_data);
    }
  }
}

int main(int argc, char** argv)
{
  try {
    std::vector<std::string> arg_list{argv, argv + argc};
    std::string text_map_filname{arg_list[1]};
    std::vector<std::string> map_strings{map::generator::read_map_strings(text_map_filname)};
    map::generator::TextMap text_map{map::generator::get_text_map_obj(map_strings)};
    text_map.show();
    map::generator::write_map_json(text_map);
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
