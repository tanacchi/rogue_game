#include <chrono>
#include <ctime>
#include <boost/algorithm/string.hpp>

#include <debug/logger.hpp>

namespace debug
{
  Logger::Logger()
    : fos_{"log/" + get_current_time_str() + ".log", std::ios::out}
  {
    log(LOG_LOCATION, "Hello", 1, 3.14, 'A');
  }

  void Logger::log(std::string location)
  {
    fos_ << '\n'
         << "\t\t" << location << '\n' << std::endl;
  }

  void Logger::log_with_name(std::list<std::string> name_list)
  {
    fos_ << std::endl;
  }

  std::list<std::string> split_string_by_comma(std::string src_string)
  {
    std::list<std::string>strings{};
    boost::split(strings, src_string, boost::is_any_of(", "),
                 boost::algorithm::token_compress_on );
    return strings;
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

