#include <mutex>  // once_flag, call_once

#include <display/display_panel.hpp>

DisplayPanel::DisplayPanel(std::size_t x, std::size_t y,
                           std::size_t width, std::size_t height)
  : win_{}
{
  std::call_once(DisplayPanel::has_initialized_, &DisplayPanel::init_screen, this);
  win_.reset(newwin(height, width, y, x));
}

DisplayPanel::~DisplayPanel()
{
}

void DisplayPanel::init_screen(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
}

std::once_flag DisplayPanel::has_initialized_{};
