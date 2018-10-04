#include <map/map_generator.hpp>
#include <rogue_game/rogue_game.hpp>

namespace map
{
  namespace generator
  {
    MapGenerator::MapGenerator(const TextMap& text_map, std::string output_filename)
      : text_map_{text_map},
        output_filename_{output_filename}
    {
    }

    void MapGenerator::set_configs()
    {
      for (std::size_t i{0}, end{text_map_.text.length()}; i < end; ++i) {
        boost::property_tree::ptree dungeon_config, item_config;
        switch (text_map_.text[i]) {
        case ' ':
          dungeon_config.put("type", "none");
          dungeon_configs_.emplace_back(dungeon_config);
          break;
        case '-':
          dungeon_config.put("type", "horizontal_wall");
          dungeon_configs_.emplace_back(dungeon_config);
          break;
        case '|':
          dungeon_config.put("type", "vertical_wall");
          dungeon_configs_.emplace_back(dungeon_config);
          break;
        case '.':
          dungeon_config.put("type", "floor");
          dungeon_configs_.emplace_back(dungeon_config);
          break;
        case '#':
          dungeon_config.put("type", "path");
          dungeon_configs_.emplace_back(dungeon_config);  
          break;
        case '+':
          dungeon_config.put("type", "door");
          dungeon_configs_.emplace_back(dungeon_config);
          break;
        case '*':
          dungeon_config.put("type", "floor");
          dungeon_configs_.emplace_back(dungeon_config);
          item_config.put("index", i);
          item_config.put("type", "gold");
          item_config.put("amount", 100);
          item_configs_.emplace_back(item_config);
          break;
        }
      }
    }
      
    void MapGenerator::write_json_map() const
    {
      boost::property_tree::ptree map_data;
      map_data.put("Map.width", text_map_.width);
      map_data.put("Map.height", text_map_.height);
  
      boost::property_tree::ptree dungeon_tree;
      for (auto config : dungeon_configs_) {
        dungeon_tree.push_back(std::make_pair("", config));
      }
      map_data.add_child("Map.elems", dungeon_tree);
        
      boost::property_tree::ptree item_tree;
      for (auto config : item_configs_) {
        item_tree.push_back(std::make_pair("", config));
      }
      map_data.add_child("Map.items", item_tree);

      boost::property_tree::write_json(map_dir+"json/"+output_filename_+".json", map_data);
    }
  }
}
