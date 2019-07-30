#include <character/inventory.hpp>

Inventory::Inventory()
  : content_{}
{
}

void Inventory::store(const ItemPtr& item_ptr)
{
  content_.emplace(item_ptr->type, item_ptr);
}

void Inventory::dispose(std::size_t target_index)
{
  auto target_itr{std::next(std::begin(content_), target_index)};
  content_.erase(target_itr);
}

std::vector<std::string> Inventory::get_item_names() const noexcept
{
  std::vector<std::string> names{};
  for (auto itr{std::begin(content_)}, end{std::end(content_)}; itr != end; ++itr)
    names.emplace_back(itr->first);
  return names;
}

const ItemPtr Inventory::get_item_by_index(const std::size_t index) const
{
  const auto& target_itr{std::next(std::begin(content_), index)};
  return target_itr->second;
}
