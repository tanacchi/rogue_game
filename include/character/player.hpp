#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <character/character.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    Player(map::Point point);
    void update(const map::Map& map) override;
  };
}

#endif  // INCLUDED_PLAYER_HPP
