#include <chrono>
#include <ctime>

#include <debug/logger.hpp>

namespace debug
{
  Logger::Logger()
    : fos_{"log/" + get_current_time_str() + ".log", std::ios::out}
  {
    fos_ << "Hello, " << get_current_time_str() << std::endl;
    fos_ << LOG_LOCATION << std::endl;
  }

  std::string Logger::get_current_time_str() const
  {
    std::chrono::system_clock::time_point now{std::chrono::system_clock::now()};
    std::time_t time{std::chrono::system_clock::to_time_t(now)};
    char time_str[20];
    std::strftime(time_str, sizeof(time_str), "%F_%T",std::localtime(&time));
    return std::string{time_str};
  }
}
