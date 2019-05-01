#ifndef INCLUDED_PLAYER_DISPLAY_HPP
#define INCLUDED_PLAYER_DISPLAY_HPP

#include <character/player.hpp>
#include <display/display_panel.hpp>

class PlayerDisplay : public DisplayPanel
{
  public:
    PlayerDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    void show(const Player& player);
};

#endif  // INCLUDED_PLAYER_DISPLAY_HPP
