#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <memory>
#include <ncurses.h>

#include <utility/logger.hpp>

struct window_ptr_deleter
{
  void operator()(WINDOW* ptr)
  {
    delwin(ptr);
  }
};

class DisplayPanel
{
  public:
    DisplayPanel(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    ~DisplayPanel();

  protected:
    std::unique_ptr<WINDOW, window_ptr_deleter> win_;
    static bool has_initialized_;
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
