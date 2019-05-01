#ifndef INCLUDED_DUNGEON_ELEM_HPP
#define INCLUDED_DUNGEON_ELEM_HPP

#include <memory>
#include <ostream>

#include <map/map_elem.hpp>

class DungeonElem : public MapElem
{
  public:
    DungeonElem(std::string type, bool can_stand);
    DungeonElem(const DungeonElem& rhs);
    virtual ~DungeonElem() = default;
    virtual std::string to_string() const;
    bool can_stand() const;

  public:
    const bool can_stand_;
};

using DungeonElemPtr = std::shared_ptr<DungeonElem>;

#endif  // INCLUDED_DUNGEON_ELEM_HPP
