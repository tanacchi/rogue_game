#include <dungeon/none.hpp>

namespace dungeon
{
  None::None()
    : DungeonElem("none", false)
  {
  }

  bool None::can_stand() const
  {
    return false;
  }
}
