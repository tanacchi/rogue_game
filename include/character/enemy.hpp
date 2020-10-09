#pragma once

#include <character/character.hpp>
#include <map/map.hpp>
#include <list>

class Enemy : public Character
{
  public:
    Enemy(Point<int> position = zero);
    void attack();
    // void suffer_damage(int amount);
    bool is_alive() const noexcept;
    void move(const Map& map, Point<int> player_pos);
};

using Enemies = std::list<Enemy>;
