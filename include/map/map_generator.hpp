#ifndef INCLUDED_MAP_GENERATOR_HPP
#define INCLUDED_MAP_GENERATOR_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <stdexcept>
#include <map>
#include <functional>

#include <map/text_map.hpp>

namespace map
{
  // マップデータ（json）を生成するクラス
  // ループで回すことになるからファンクタ化しようと思うけど後回し
  class MapGenerator
  {
  public:
    MapGenerator(const TextMap& text_map, std::string output_filename = "tmp_sample_map");

    // ダンジョン要素・アイテム要素の ptree の配列を TextMap より生成する
    void set_configs();

    // ptree の配列から json ファイルを書き出す
    void write_json_map() const;
  private:
    const TextMap text_map_;
    const std::string output_filename_;

    // ダンジョン要素の ptree の配列
    std::vector<boost::property_tree::ptree> dungeon_configs_;
    // アイテム要素の ptree の配列
    std::vector<boost::property_tree::ptree> item_configs_;
  };
}

#endif  // INCLUDED_MAP_GENERATOR_HPP
