#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <map>
#include <vector>
#include <boost/filesystem.hpp>
// #include <string_view>  // In C++17

#include <debug/logger.hpp>
#include <dungeon/dungeon_elem.hpp>
#include <item/item.hpp>
#include <map/map_elem.hpp>
#include <map/point.hpp>

const std::string map_dir{boost::filesystem::current_path().string() + "/map/"};
// constexpr std::string_view map_dir{boost::filesystem::current_path().string() + "/map/"};

struct Map
{
  Map() = default;
  Map(Map&& map);
  Map& operator=(Map&& map) noexcept;
  friend std::ostream& operator<<(std::ostream& os, const Map& map);

  std::size_t width;
  std::size_t height;

  // プレイヤーの初期位置
  Point<int> initial_position;

  // ダンジョン要素・アイテム要素はそれぞれ（連想）配列としてまとめ、
  // レイヤーとして扱う
  std::vector<::DungeonElemPtr> dungeon_layer;
  std::map<Point<int>, ::item::ItemPtr> item_layer;

  // 位置情報から該当するダンジョン要素のコピーを取得する
  const ::DungeonElem get_dungeon_elem(const Point<int>& point) const;
  bool in_range(const Point<std::size_t>& point) const;
};

#endif  // INCLUDED_MAP_HPP
