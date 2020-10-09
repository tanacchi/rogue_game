#ifndef INCLUDED_INVENTORY_HPP
#define INCLUDED_INVENTORY_HPP

#include <map>
#include <vector>

#include <item/item.hpp>

class Inventory
{
  public:
    using ContentType = std::multimap<std::string, const ItemPtr>;
    using ElemType = ContentType::value_type;

    Inventory();
    void store(const ItemPtr& item_ptr);
    void dispose(std::size_t target_index);
    const std::vector<ItemPtr> get_items() const;

  private:
    ContentType content_;
};

#endif  // INCLUDED_INVENTORY_HPP
