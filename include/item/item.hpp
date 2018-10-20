#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <ostream>

#include <map/map_elem.hpp>
#include <map/point.hpp>

namespace character
{
  class Player;
}

namespace item
{
  // アイテムの基底クラス
  // マップデータに記述されるので MapElem を継承
  // 取得（インベントリに追加） → 使用のプロセスを設ける予定
  class Item : public ::map::MapElem
  {
  public:
    Item(std::string type);
    Item(Item&& rhs) noexcept;
    virtual void use(character::Player* const player_ptr);
    virtual ~Item() = default;
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
  };
}

#endif  // INCLUDED_ITEM_HPP
