#include <item/gold.hpp>

namespace item
{
  Gold::Gold(std::string type, std::size_t amount)
    : Item(type),
      amount_{amount}
  {
  }
}
