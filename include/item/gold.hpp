#ifndef INCLUDED_GOLD_HPP
#define INCLUDED_GOLD_HPP

#include <ostream>

#include <item/item.hpp>

// 触れると所持金が増えるアイテム
class Gold : public Item
{
  public:
    Gold(std::size_t amount = 100);
    void use(character::Player* const player_ptr);
    std::string to_string() const;
  private:
    const std::size_t amount_;
};

#endif  // INCLUDED_GOLD_HPP
