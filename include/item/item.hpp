#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <ostream>
#include <memory>

#include <map/map_elem.hpp>
#include <map/point.hpp>
#include <debug/logger.hpp>

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
    virtual std::string to_string() const;
  };

  using ItemPtr = std::unique_ptr<Item>;
}

#endif  // INCLUDED_ITEM_HPP
