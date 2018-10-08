#include <display/display_panel.hpp>

DisplayPanel::DisplayPanel(std::size_t x, std::size_t y,
                           std::size_t width, std::size_t height)
  : win_{std::unique_ptr<WINDOW>(newwin(height, width, y, x))}
{
}

DisplayPanel::~DisplayPanel()
{
  delwin(win_.get());
}
