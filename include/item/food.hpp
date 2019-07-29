#ifndef INCLUDED_FOOD_HPP
#define INCLUDED_FOOD_HPP

#include <item/item.hpp>

//  ':'
class Food : public Item
{
  public:
    Food(std::size_t amount = 100);
    std::size_t get_amount() const noexcept;
    std::string to_string() const;

  private:
    const std::size_t amount_;
};

#endif  // INCLUDED_FOOD_HPP
