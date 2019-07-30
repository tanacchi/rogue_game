#include <display/message_display.hpp>

MessageDisplay::MessageDisplay(std::size_t x, std::size_t y,
                               std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MessageDisplay::show()
{
  wclear(win_.get());
  box(win_.get(), ACS_VLINE, ACS_HLINE);
  wrefresh(win_.get());
}
