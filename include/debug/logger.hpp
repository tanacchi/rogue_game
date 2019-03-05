#ifndef INCLUDED_LOGGER_HPP
#define INCLUDED_LOGGER_HPP

#include <fstream>
#include <list>

#define LOG_LOCATION (std::string{__FILE__}+":"+std::to_string(__LINE__))
#define LOG_VALUES(...) debug::Logger::log_with_name(debug::split_string_by_comma(#__VA_ARGS__", "+LOG_LOCATION), __VA_ARGS__)
#define LOG_STRING(arg) debug::Logger::log_string(arg); debug::Logger::log_string("\t\t\t\t["+LOG_LOCATION+"]\n\n", ' ')

namespace debug
{
  class Logger
  {
  public:
    static void log_with_name(std::list<std::string>&& name_list);

    template <typename Head, typename... Tail>
    static void log_with_name(std::list<std::string>&& name_list, const Head& head, const Tail&... tail)
    {
      if (!Logger::fos_.is_open()) init_log_file();
      fos_ << "{ " << name_list.front() << " : " << head << " }\n";
      name_list.pop_front();
      log_with_name(std::move(name_list), std::forward<const Tail&>(tail)...);
    }

    template <typename Head, typename... Tail>
    static void log_with_name(std::list<std::string>&& name_list, Head&& head, Tail&&... tail)
    {
      if (!Logger::fos_.is_open()) init_log_file();
      fos_ << "{ " << name_list.front() << " : " << head << " }\n";
      name_list.pop_front();
      log_with_name(std::move(name_list), std::forward<Tail&&>(tail)...);
    }

    static void log_string(const std::string& str, char separate_char = '=');    
  private:
    static void init_log_file();

    static std::fstream fos_;
  };
  std::string get_current_time_str();
  std::list<std::string> split_string_by_comma(std::string src_string);
}

#endif  // INCLUDED_LOGGER_HPP
