#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <map/map_elem.hpp>
#include <map/point.hpp>

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
    virtual ~Item() = default;
  };
}

#endif  // INCLUDED_ITEM_HPP
