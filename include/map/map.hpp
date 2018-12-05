#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <ostream>
#include <valarray>
#include <memory>
#include <map>
#include <vector>

#include <map/map_elem.hpp>
#include <map/point.hpp>
#include <dungeon/dungeon_elem.hpp>
#include <item/item.hpp>

namespace map
{
  struct Map
  {
    Map() = default;
    Map(Map&& map);
    friend std::ostream& operator<<(std::ostream& os, const Map& map);
    
    std::size_t width;
    std::size_t height;

    // プレイヤーの初期位置
    map::Point<int> initial_position;

    // ダンジョン要素・アイテム要素はそれぞれ（連想）配列としてまとめ、
    // レイヤーとして扱う
    std::vector<std::unique_ptr<::dungeon::DungeonElem> > dungeon_layer;
    std::map<Point<int>, std::unique_ptr<::item::Item> > item_layer;

    // 位置情報から該当するダンジョン要素のコピーを取得する
    const ::dungeon::DungeonElem get_dungeon_elem(const Point<int>& point) const;
    bool in_range(const Point<std::size_t>& point) const;

    // インデックスから位置情報に変換する
    // 初期化でしか使わないから別の場所に移動したい
    Point<int> index_to_point(std::size_t index);
  };

  // マップデータ（json）からインスタンスを生成
  // コンストラクタでいいな
  Map read_map(const std::string mapfile_name);

  // ダンジョン要素の種類からダンジョン要素のインスタンスを生成しポインタを返す
  // オブジェクト・ファクトリ的な役割
  std::unique_ptr<::dungeon::DungeonElem> gen_dungeon_elem(std::string type);
}

#endif  // INCLUDED_MAP_HPP
