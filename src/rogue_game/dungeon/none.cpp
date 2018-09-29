#include <dungeon/none.hpp>

namespace dungeon
{
  None::None(std::string type)
    : DungeonElem(type)
  {
  }

  bool None::can_stand() const
  {
    return false;
  }
}
