#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <ostream>
#include <cstddef>
#include <memory>

#include <keyboard/keyboard_manager.hpp>
#include <map/map.hpp>
#include <map/point.hpp>

namespace character
{
  // キャラクターの基底クラス
  // Player に加え Enemy が継承する予定
  class Character
  {
  public:
    // デフォルト引数はそのうちなくす予定
    Character(map::Point position = map::Point{0, 0});
    
    // キャラクターの位置を取得
    map::Point get_position() const;

    // キャラクターの位置を設定
    void set_position(const map::Point& point);

    friend std::ostream& operator<<(std::ostream& os, const Character& character);
  protected:
    map::Point position_;
  };
}

#endif  // INCLUDED_CHARACTER_HPP
