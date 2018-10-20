#include <item/gold.hpp>

namespace item
{
  Gold::Gold(std::size_t amount)
    : Item("gold"),
      amount_{amount}
  {
  }

  std::ostream& operator<<(std::ostream& os, const Gold& gold)
  {
    os << "{ type : " << gold.type << " }, { amount : " << gold.amount_ << " }";
    return os;
  }
}
