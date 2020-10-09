#include <character/enemy.hpp>

Enemy::Enemy(Point<int> position)
  : Character(position)
{
}

void Enemy::attack()
{
}

bool Enemy::is_alive() const noexcept
{
  return hit_point_ >= 0;
}
