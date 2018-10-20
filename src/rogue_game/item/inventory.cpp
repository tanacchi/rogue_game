#include <item/inventory.hpp>

Inventory::Inventory(std::size_t capacity)
  : items_{},
    capacity_{capacity}
{
}

void Inventory::store(std::unique_ptr<item::Item>&& item)
{
  items_.push_back(std::move(item));
  debug::Logger::log_string("Item just stored", '-');
}
