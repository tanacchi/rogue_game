#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <map>

#include <character/character.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    Player(map::Point point);
    static const std::map<KeyboardManager::KeyState, map::Point> motion_table;
    std::size_t get_money() const;
    void update(map::Map& map) override;
    void update(map::Map& map, const KeyboardManager::KeyState key_state);

  private:
    std::size_t money_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
