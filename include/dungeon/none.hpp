#ifndef INCLUDED_NONE_HPP
#define INCLUDED_NONE_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  // ダンジョン要素　' '
  // 隠し通路なんかにも使えるかと思って
  // 空白もマップの要素にしてる
  class None : public DungeonElem
  {
  public:
    None();
  };
}

#endif  // INCLUDED_NONE_HPP
