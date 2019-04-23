#ifndef INCLUDED_MAP_DISPLAY_HPP
#define INCLUDED_MAP_DISPLAY_HPP

#include <character/player.hpp>
#include <display/display_panel.hpp>
#include <map/map.hpp>

// マップ（タンジョン・アイテム・キャラクター）の表示
class MapDisplay : public DisplayPanel
{
  public:
    MapDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    void show(Map& map, const Player& player);
};

#endif  // INCLUDED_MAP_DISPLAY_HPP
