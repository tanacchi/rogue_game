#ifndef INCLUDED_LOGGER_HPP
#define INCLUDED_LOGGER_HPP

#include <fstream>

namespace debug
{
  class Logger
  {
  public:
    Logger();
  private:
    std::string get_current_time_str() const;
    std::fstream fos_;
  };
}

#endif  // INCLUDED_LOGGER_HPP
