#ifndef INCLUDED_MAP_READER_HPP
#define INCLUDED_MAP_READER_HPP

#include <map/map.hpp>

namespace map
{
  class MapReader
  {
  public:
    Map operator()(std::string map_filename);
  };

  // ダンジョン要素の種類からダンジョン要素のインスタンスを生成しポインタを返す
  // オブジェクト・ファクトリ的な役割
  ::dungeon::DungeonElemPtr gen_dungeon_elem(std::string type);
}

#endif // INCLUDED_MAP_READER_HPP
