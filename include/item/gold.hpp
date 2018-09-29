#ifndef INCLUDED_GOLD_HPP
#define INCLUDED_GOLD_HPP

#include <item/item.hpp>

namespace item
{
  class Gold : public Item
  {
  public:
    Gold(std::string type, std::size_t amount = 100);
  private:
    const std::size_t amount_;
  };
}

#endif  // INCLUDED_GOLD_HPP
