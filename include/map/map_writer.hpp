#ifndef INCLUDED_MAP_GENERATOR_HPP
#define INCLUDED_MAP_GENERATOR_HPP

#include <stdexcept>
#include <map>
#include <functional>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

#include <map/map.hpp>
#include <map/text_map.hpp>

namespace map
{
  using ConfigType = boost::property_tree::ptree;

  // マップデータ（json）を生成するクラス
  // ループで回すことになるからファンクタ化しようと思うけど後回し
  class MapWriter
  {
  public:
    // ダンジョン要素・アイテム要素の ptree の配列を TextMap より生成する
    void set_configs(const TextMap& text_map, std::vector<ConfigType>& dungeon_configs, std::vector<ConfigType>& item_configs);

    // ptree の配列から json ファイルを書き出す
    void write_json_map(const TextMap& text_map,
                        const std::vector<ConfigType>& dungeon_configs, 
                        const std::vector<ConfigType>& item_configs,
                        const std::string& output_filename) const;

    void operator()(const TextMap& text_map, const std::string& output_filename = "tmp_sample_map");
  };
}

#endif  // INCLUDED_MAP_GENERATOR_HPP
