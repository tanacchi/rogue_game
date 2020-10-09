#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <memory>
#include <mutex>  // once_flag
#include <ncurses.h>

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
    static std::once_flag has_initialized_;

  private:
    void init_screen(void);
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
