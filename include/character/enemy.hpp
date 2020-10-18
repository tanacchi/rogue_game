#pragma once

#include <character/character.hpp>
#include <map/map.hpp>
#include <list>
#include <random>

class Enemy : public Character
{
  public:
    Enemy(Point<int> position = zero);
    void attack();
    // void suffer_damage(int amount);
    bool is_alive() const noexcept;
    void move(const Map& map, Point<int> player_pos, std::default_random_engine& engine);

  private:
    std::uniform_int_distribution<std::size_t> dist_;
};

using Enemies = std::list<Enemy>;
