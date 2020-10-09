#pragma once

#include <character/character.hpp>

class Enemy : public Character
{
  public:
    Enemy(Point<int> position = zero);
    void attack();
    // void suffer_damage(int amount);
    bool is_alive() const noexcept;
};
