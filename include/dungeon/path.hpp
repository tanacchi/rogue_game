#ifndef INCLUDED_PATH_HPP
#define INCLUDED_PATH_HPP

#include <dungeon/dungeon_elem.hpp>

namespace dungeon
{
  class Path : public DungeonElem
  {
  public:
    Path(std::string type);
    bool can_stand() const;
  };
}

#endif  // INCLUDED_PATH_HPP
