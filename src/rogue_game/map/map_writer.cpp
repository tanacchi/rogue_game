#include <map/map_writer.hpp>

namespace map
{
  // マップの文字からそれぞれ json の内容を追加
  // ダンジョン要素とアイテム要素は別々
  void MapWriter::set_configs(const TextMap& text_map, std::vector<ConfigType>& dungeon_configs, std::vector<ConfigType>& item_configs)
  {
    for (std::size_t i{0}, end{text_map.text.length()}; i < end; ++i) {
      ConfigType dungeon_config, item_config;
      switch (text_map.text[i]) {
        case ' ':
          dungeon_config.put("type", "none");
          break;
        case '-':
          dungeon_config.put("type", "horizontal_wall");
          break;
        case '|':
          dungeon_config.put("type", "vertical_wall");
          break;
        case '.': case '@':
          dungeon_config.put("type", "floor");
          break;
        case '#':
          dungeon_config.put("type", "path");
          break;
        case '+':
          dungeon_config.put("type", "door");
          break;
        case '*':
          dungeon_config.put("type", "floor");
          item_config.put("type", "gold");
          item_config.put("index", i);
          item_config.put("amount", 100);
          break;
      }
      dungeon_configs.emplace_back(dungeon_config);
      if (!item_config.empty()) 
      {
        item_configs.emplace_back(item_config);
      }
    }
  }

  void MapWriter::write_json_map(const TextMap& text_map, 
                                 const std::vector<ConfigType>& dungeon_configs,
                                 const std::vector<ConfigType>& item_configs,
                                 const std::string& output_filename) const
  {
    ConfigType map_data;
    map_data.put("Map.width", text_map.width);
    map_data.put("Map.height", text_map.height);
    map_data.put("Map.player_pos", text_map.text.find('@'));
    ConfigType dungeon_tree;
    for (auto config : dungeon_configs) {
      dungeon_tree.push_back(std::make_pair("", config));
    }
    map_data.add_child("Map.elems", dungeon_tree);

    ConfigType item_tree;
    for (auto config : item_configs) {
      item_tree.push_back(std::make_pair("", config));
    }
    map_data.add_child("Map.items", item_tree);

    // map_dir は include/rogue_game.hpp にて自動生成される
    boost::property_tree::write_json(map_dir+"json/"+output_filename+".json", map_data);
  }

  void MapWriter::operator()(const TextMap& text_map, const std::string& output_filename)
  {
    std::vector<ConfigType> dungeon_configs{};
    std::vector<ConfigType> item_configs{};
    set_configs(text_map, dungeon_configs, item_configs);
    write_json_map(text_map, dungeon_configs, item_configs, output_filename);
  }
}
