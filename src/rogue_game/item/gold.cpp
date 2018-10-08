#include <item/gold.hpp>

namespace item
{
  Gold::Gold(std::size_t amount)
    : Item("gold"),
      amount_{amount}
  {
  }
}
