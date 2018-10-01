#ifndef INCLUDED_NONE_HPP
#define INCLUDED_NONE_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class None : public DungeonElem
  {
  public:
    None();
    bool can_stand() const;
  };
}

#endif  // INCLUDED_NONE_HPP
