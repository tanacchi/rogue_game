#include <thread>
#include <chrono>

#include <display/message_display.hpp>

MessageDisplay::MessageDisplay(std::size_t x, std::size_t y,
                               std::size_t width, std::size_t height)
  : DisplayPanel(x, y, width, height)
{
}

void MessageDisplay::show(const std::vector<std::string>& messages)
{
  werase(win_.get());
  for (const auto& message : messages)
  {
    werase(win_.get());
    mvwinsstr(win_.get(), 1, 1, message.c_str());
    box(win_.get(), ACS_VLINE, ACS_HLINE);
    wrefresh(win_.get());
    wgetch(win_.get());
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  box(win_.get(), ACS_VLINE, ACS_HLINE);
  wrefresh(win_.get());
}
