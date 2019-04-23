#ifndef INCLUDED_MAP_READER_HPP
#define INCLUDED_MAP_READER_HPP

#include <functional>
#include <unordered_map>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <map/map.hpp>

class MapReader
{
  public:
    Map operator()(std::string map_filename);
};

// ダンジョン要素の種類からダンジョン要素のインスタンスを生成しポインタを返す
// オブジェクト・ファクトリ的な役割
::dungeon::DungeonElemPtr gen_dungeon_elem(std::string type);
::item::ItemPtr gen_item_elem(std::string type, boost::property_tree::ptree property);

#endif // INCLUDED_MAP_READER_HPP
