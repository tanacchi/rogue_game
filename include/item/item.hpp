#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <memory>
#include <ostream>

#include <map/map_elem.hpp>

class Player;

class Item : public MapElem
{
  public:
    Item(std::string type);
    Item(const Item& item) = default;
    Item(Item&& rhs) noexcept;
    virtual ~Item() = default;
    virtual std::string to_string() const;
};

using ItemPtr = std::shared_ptr<Item>;

#endif  // INCLUDED_ITEM_HPP
