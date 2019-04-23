#ifndef INCLUDED_VERTICAL_WALL_HPP
#define INCLUDED_VERTICAL_WALL_HPP

#include <dungeon/dungeon_elem.hpp>

// ダンジョン要素　'|'
// マップ生成機能の予定があるので '|' と '-' は区別してる
class VerticalWall : public DungeonElem
{
  public:
    VerticalWall();
};

#endif  // INCLUDED_VERTICAL_WALL_HPP
