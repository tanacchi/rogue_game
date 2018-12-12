#include <string>

#include <map/map_writer.hpp>
#include <rogue_game/rogue_game.hpp>

namespace map
{
  MapWriter::MapWriter(const TextMap& text_map, std::string output_filename)
    : text_map_{text_map},
    output_filename_{output_filename}
  {
  }

  // マップの文字からそれぞれ json の内容を追加
  // ダンジョン要素とアイテム要素は別々
  void MapWriter::set_configs()
  {
    for (std::size_t i{0}, end{text_map_.text.length()}; i < end; ++i) {
      ConfigType dungeon_config, item_config;
      switch (text_map_.text[i]) {
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
          item_config.put("index", i);
          item_config.put("type", "gold");
          item_config.put("amount", 100);
          break;
      }
      dungeon_configs_.emplace_back(dungeon_config);
      item_configs_.emplace_back(item_config);
    }
  }

  void MapWriter::write_json_map() const
  {
    ConfigType map_data;
    map_data.put("Map.width", text_map_.width);
    map_data.put("Map.height", text_map_.height);
    map_data.put("Map.player_pos", text_map_.text.find('@'));
    ConfigType dungeon_tree;
    for (auto config : dungeon_configs_) {
      dungeon_tree.push_back(std::make_pair("", config));
    }
    map_data.add_child("Map.elems", dungeon_tree);

    ConfigType item_tree;
    for (auto config : item_configs_) {
      item_tree.push_back(std::make_pair("", config));
    }
    map_data.add_child("Map.items", item_tree);

    // map_dir は include/rogue_game.hpp にて自動生成される
    boost::property_tree::write_json(map_dir+"json/"+output_filename_+".json", map_data);
  }
}
