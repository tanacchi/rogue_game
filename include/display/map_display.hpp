#ifndef INCLUDED_MAP_DISPLAY_HPP
#define INCLUDED_MAP_DISPLAY_HPP

#include <display/display_panel.hpp>
#include <character/enemy.hpp>

class Player;
class Map;

class MapDisplay : public DisplayPanel
{
  public:
    MapDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    void show(const Map& map, const Player& player, const Enemies& enemies);
};

#endif  // INCLUDED_MAP_DISPLAY_HPP
