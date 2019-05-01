#include <sstream>

#include <character/player.hpp>
#include <item/gold.hpp>

Gold::Gold(std::size_t amount)
  : Item("gold")
  , amount_{amount}
{
}

void Gold::use(Player* const player_ptr)
{
  player_ptr->add_money(amount_);
}

std::string Gold::to_string() const
{
  std::stringstream ss{};
  ss << Item::to_string() << ", { amount : " << amount_ << " }";
  return ss.str();
}
