#ifndef INCLUDED_INVENTORY_HPP
#define INCLUDED_INVENTORY_HPP

#include <list>
#include <memory>

#include <item/item.hpp>
#include <debug/logger.hpp>

class Inventory
{
public:
  Inventory(std::size_t capacity);
  void store(std::unique_ptr<item::Item>&& item);
private:
  std::list<std::unique_ptr<item::Item> > items_;
  std::size_t capacity_;
};

#endif  // INCLUDED_INVENTORY_HPP
