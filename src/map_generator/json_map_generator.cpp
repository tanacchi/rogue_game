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

namespace map
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
    
  namespace generator
  {
    class MapGenerator
    {
    public:
      MapGenerator(const TextMap& text_map, std::string output_filename = "tmp_sample_map")
        : text_map_{text_map},
          output_filename_{output_filename}
      {
      }

      void set_elem_config_table()
      {
        using ptree = boost::property_tree::ptree;
        elem_config_table_ = {
          {' ', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "none");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'-', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "horizontal_wall");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'|', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "vertical_wall");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'.', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "floor");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'#', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "path");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'+', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "door");
              dungeon_configs_.emplace_back(dungeon_config);
            }},
          {'*', [&]{
              ptree dungeon_config;
              dungeon_config.put("type", "floor");
              dungeon_configs_.emplace_back(dungeon_config);
              ptree item_config;
              item_config.put("type", "gold");
              item_configs_.emplace_back(item_config);
            }}
        };
      }

      void set_configs()
      {
        for (std::size_t i{0}, end{text_map_.text.length()}; i < end; ++i) {
          elem_config_table_.at(text_map_.text[i])();
        }
      }
      
      void write_map_json()
      {
        boost::property_tree::ptree map_data;
        map_data.put("Map.width", text_map_.width);
        map_data.put("Map.height", text_map_.height);
  
        boost::property_tree::ptree dungeon_tree;
        for (auto config : dungeon_configs_) {
          dungeon_tree.push_back(std::make_pair("", config));
        }
        map_data.add_child("Map.elems", dungeon_tree);
        
        boost::property_tree::write_json(map_dir+"json/"+output_filename_+".json", map_data);
      }
    private:
      const TextMap text_map_;
      const std::string output_filename_;
      std::map<char, std::function<void(void)> > elem_config_table_;
      std::vector<boost::property_tree::ptree> dungeon_configs_;
      std::vector<boost::property_tree::ptree> item_configs_;
    };
     
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
    map_generator.write_map_json();
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
