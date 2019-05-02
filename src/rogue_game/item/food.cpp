#include <sstream>

#include <item/food.hpp>

Food::Food(std::size_t amount)
  : Item("food")
  , amount_{amount}
{
}

std::string Food::to_string() const
{
  std::stringstream ss{};
  ss << Item::to_string() << ", { amount : " << amount_ << " }";
  return ss.str();
}
