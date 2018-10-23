#ifndef INCLUDED_LOGGER_HPP
#define INCLUDED_LOGGER_HPP

#include <fstream>
#include <list>

#define LOG_LOCATION (std::string{__FILE__}+":"+std::to_string(__LINE__))
#define LOG_VALUES(...) debug::Logger::log_with_name(debug::split_string_by_comma(#__VA_ARGS__", "+LOG_LOCATION), __VA_ARGS__)

namespace debug
{
  class Logger
  {
  public:
    static void log_with_name(std::list<std::string>&& name_list);

    template <typename Head, typename... Tail>
    static void log_with_name(std::list<std::string>&& name_list, const Head& head, const Tail&... tail)
    {
      fos_ << "{ " << name_list.front() << " : " << head << " }\n";
      name_list.pop_front();
      log_with_name(std::move(name_list), std::forward<const Tail&>(tail)...);
    }

    template <typename Head, typename... Tail>
    static void log_with_name(std::list<std::string>&& name_list, Head&& head, Tail&&... tail)
    {
      fos_ << "{ " << name_list.front() << " : " << head << " }\n";
      name_list.pop_front();
      log_with_name(std::move(name_list), std::forward<Tail&&>(tail)...);
    }

    static void log_string(const std::string& str, char separate_char = '=');    
  private:
    static std::fstream fos_;
  };
  std::string get_current_time_str();
  std::list<std::string> split_string_by_comma(std::string src_string);
}

#endif  // INCLUDED_LOGGER_HPP
