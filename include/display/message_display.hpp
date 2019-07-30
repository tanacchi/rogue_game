#ifndef INCLUDED_MESSAGE_DISPLAY_HPP
#define INCLUDED_MESSAGE_DISPLAY_HPP

#include <vector>

#include <display/display_panel.hpp>

class MessageDisplay : public DisplayPanel
{
  public:
    MessageDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    void show(const std::vector<std::string>& messages);
};

#endif  // INCLUDED_MESSAGE_DISPLAY_HPP
