#include <item/inventory.hpp>
#include <item/gold.hpp>

Inventory::Inventory(std::size_t capacity)
  : items_{},
    capacity_{capacity}
{
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory)
{
  os << "\n{ items :\n";
  for (std::list<std::unique_ptr<item::Item> >::const_iterator it{inventory.items_.begin()}, end{inventory.items_.end()};
       it != end; ++it, os.put('\n')) {
    const auto* const item {dynamic_cast<item::Gold *>((*it).get())}; // REFACTOR REQUIRED
    os << *item;
  }
  os << "},\n { capacity : " << inventory.capacity_ << " }\n";
  return os;
}

void Inventory::store(std::unique_ptr<item::Item>&& item)
{
  items_.push_back(std::move(item));
  debug::Logger::log_string("Item just stored", '-');
  LOG_VALUES(*this);
}
