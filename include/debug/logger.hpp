#ifndef INCLUDED_LOGGER_HPP
#define INCLUDED_LOGGER_HPP

#include <fstream>

#define LOG_LOCATION (std::string{__FILE__}+" : "+std::to_string(__LINE__))

namespace debug
{
  class Logger
  {
  public:
    Logger();
    void log(std::string location);
    template<typename Head, typename... Tail>
    void log(std::string location, Head head, Tail... tail);
  private:
    std::string get_current_time_str() const;
    std::fstream fos_;
  };
}

#endif  // INCLUDED_LOGGER_HPP
