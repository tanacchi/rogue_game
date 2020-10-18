#include <array>
#include <character/enemy.hpp>
#include <action/enemy_action.hpp>
#include <utility/point.hpp>

Enemy::Enemy(Point<int> position)
  : Character(position)
  , dist_(0ul, 3ul)
{
}

void Enemy::attack()
{
}

bool Enemy::is_alive() const noexcept
{
  return hit_point_ >= 0;
}

void Enemy::move(const Map& map, const Point<int> player_pos, std::default_random_engine& engine)
{
  const std::array<const Point<int>, 4> directions{up, right, down, left};
  const auto dist_to_player{norm(position_ - player_pos)};
  Point<int> next_pos;
  do
  {
    const auto& pos_delta = directions[dist_(engine)];
    next_pos = position_ + pos_delta;
  } while (next_pos == player_pos
           || !map.in_range(next_pos)
           || !map.get_dungeon_elem(next_pos).can_stand());
  position_ = next_pos;
}
