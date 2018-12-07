#include <item/gold.hpp>
#include <character/player.hpp>

namespace item
{
  Gold::Gold(std::size_t amount)
    : Item("gold"),
      amount_{amount}
  {
  }

  void Gold::use(character::Player* const player_ptr)
  {
    player_ptr->add_money(amount_);
  }

  std::ostream& operator<<(std::ostream& os, const Gold& gold)
  {
    os << "{ type : " << gold.type << " }, { amount : " << gold.amount_ << " }";
    return os;
  }
}
