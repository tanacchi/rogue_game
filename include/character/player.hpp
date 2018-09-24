#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <character/character.hpp>

class Player : public Character
{
public:
  Player(map::Point point);
};

#endif  // INCLUDED_PLAYER_HPP
