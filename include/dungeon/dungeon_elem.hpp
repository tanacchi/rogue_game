#ifndef INCLUDED_DUNGEON_ELEM_HPP
#define INCLUDED_DUNGEON_ELEM_HPP

#include <ostream>

#include <map/map_elem.hpp>

namespace dungeon
{
  // ダンジョン要素の基底クラス
  class DungeonElem : public ::map::MapElem
  {
  public:
    DungeonElem(std::string type, bool can_stand);
    DungeonElem(const DungeonElem& rhs);
    virtual ~DungeonElem() = default;
    friend std::ostream& operator<<(std::ostream& os, const DungeonElem& elem);
    
    // キャラクターが移動可能かの判定に使われる
    bool can_stand() const;
  public:
    // マップ要素の静的クラス変数にしてもいいんだけど
    // こっちのが若干自由度高そう
    const bool can_stand_;
  };
}

#endif  // INCLUDED_DUNGEON_ELEM_HPP
