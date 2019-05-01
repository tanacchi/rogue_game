#ifndef INCLUDED_ITEM_HPP
#define INCLUDED_ITEM_HPP

#include <memory>
#include <ostream>

#include <debug/logger.hpp>
#include <map/map_elem.hpp>
#include <map/point.hpp>

class Player;

class Item : public MapElem
{
  public:
    Item(std::string type);
    Item(const Item& item) = default;
    Item(Item&& rhs) noexcept;
    virtual void use(Player* const player_ptr);
    virtual ~Item() = default;
    virtual std::string to_string() const;
};

using ItemPtr = std::shared_ptr<Item>;

#endif  // INCLUDED_ITEM_HPP
