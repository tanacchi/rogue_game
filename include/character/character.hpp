#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <ostream>

#include <debug/logger.hpp>
#include <map/point.hpp>

namespace character
{
  // キャラクターの基底クラス
  // Player に加え Enemy が継承する予定
  class Character
  {
  public:
    // デフォルト引数はそのうちなくす予定
    Character(map::Point<int> position = map::zero);
    
    // キャラクターの位置を取得
    map::Point<int> get_position() const;  // const& にする？

    // キャラクターの位置を設定
    void set_position(const map::Point<int>& point);

    friend std::ostream& operator<<(std::ostream& os, const Character& character);
  protected:
    map::Point<int> position_;
  };
}

#endif  // INCLUDED_CHARACTER_HPP
