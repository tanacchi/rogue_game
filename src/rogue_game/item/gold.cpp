#include <item/gold.hpp>

namespace item
{
  Gold::Gold(::map::Point position, std::size_t amount)
    : Item("gold", position),
      amount_{amount}
  {
  }
}
