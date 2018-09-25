#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <character/character.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    Player(map::Point point, std::unique_ptr<KeyboardManager>&& km_ptr=nullptr);
    void update(const map::Map& map) override;
  private:
    std::unique_ptr<KeyboardManager> km_ptr_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
