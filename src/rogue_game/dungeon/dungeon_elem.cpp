#include <sstream>

#include <dungeon/dungeon_elem.hpp>

DungeonElem::DungeonElem(std::string type, bool can_stand)
  : MapElem(type)
  , can_stand_{can_stand}
{
}

DungeonElem::DungeonElem(const DungeonElem& rhs)
  : MapElem(rhs.type)
  , can_stand_{rhs.can_stand_}
{
}

std::string DungeonElem::to_string() const
{
  std::stringstream ss;
  ss << MapElem::to_string()
    << ", { can_stand_ : " << can_stand_ << " }";
  return ss.str();
}

bool DungeonElem::can_stand() const
{
  return can_stand_;
}
