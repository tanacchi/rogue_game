#include <dungeon/none.hpp>

namespace dungeon
{
  None::None()
    : DungeonElem("none")
  {
  }

  bool None::can_stand() const
  {
    return false;
  }
}
