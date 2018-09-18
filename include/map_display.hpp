#ifndef INCLUDED_MAP_DISPLAY_HPP
#define INCLUDED_MAP_DISPLAY_HPP

#include <display_panel.hpp>

class MapDisplay : public DisplayPanel
{
public:
  MapDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
  void read_map(std::string mapfile_name);
};

#endif  // INCLUDED_MAP_DISPLAY_HPP
