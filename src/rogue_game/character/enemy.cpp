#include <array>
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

void Enemy::move(const Map& map, const Point<int> player_pos)
{
  const std::array<const Point<int>, 4> directions{up, right, down, left};
  for (const auto dir : directions)
  {
    const auto next_pos = position_ + dir;
    if (next_pos != player_pos
        && map.in_range(next_pos)
        && map.get_dungeon_elem(next_pos).can_stand())
    {
      position_ = next_pos;
      break;
    }
  }
}
