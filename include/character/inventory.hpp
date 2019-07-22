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
    std::vector<std::string> get_item_names() const noexcept;
    const ItemPtr get_item_by_index(const std::size_t index) const;

  private:
    ContentType content_;
};

#endif  // INCLUDED_INVENTORY_HPP
