#ifndef INCLUDED_GOLD_HPP
#define INCLUDED_GOLD_HPP

#include <ostream>

#include <item/item.hpp>

namespace item
{
  // 触れると所持金が増えるアイテム
  class Gold : public Item
  {
  public:
    Gold(std::size_t amount = 100);
    void use(character::Player* const player_ptr);
    friend std::ostream& operator<<(std::ostream& os, const Gold& gold);
  private:
    const std::size_t amount_;
  };
}

#endif  // INCLUDED_GOLD_HPP
