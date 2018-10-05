#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <character/character.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    Player(map::Point point);
    std::size_t get_money() const;
    void update(map::Map& map) override;
    void update(map::Map& map, const KeyboardManager::KeyState key_state);
  private:
    std::size_t money_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
