#ifndef INCLUDED_GOLD_HPP
#define INCLUDED_GOLD_HPP

#include <ostream>

#include <item/item.hpp>

// '*'
class Gold : public Item
{
  public:
    Gold(std::size_t amount = 100);
    std::string to_string() const;
    std::size_t get_amount() const noexcept;

  private:
    const std::size_t amount_;
};

#endif  // INCLUDED_GOLD_HPP
