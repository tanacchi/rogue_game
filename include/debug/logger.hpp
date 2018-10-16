#ifndef INCLUDED_LOGGER_HPP
#define INCLUDED_LOGGER_HPP

#include <fstream>
#include <list>

#define LOG_LOCATION (std::string{__FILE__}+" : "+std::to_string(__LINE__))
#define LOG_WITH_NAME(...) logger.log_with_name(debug::split_string_by_comma(#__VA_ARGS__), __VA_ARGS__)

namespace debug
{
  class Logger
  {
  public:
    Logger();
    void log(std::string location); 

    template<typename Head, typename... Tail>
    void log(std::string location, Head head, Tail... tail)
    {
      fos_ << head << ' ';
      log(location, std::forward<Tail>(tail)...);
    }

    void log_with_name(std::list<std::string> name_list);

    template <typename Head, typename... Tail>
    void log_with_name(std::list<std::string> name_list, Head head, Tail... tail)
    {
      fos_ << "{ " << name_list.front() << " : " << head << " } ";
      name_list.pop_front();
      log_with_name(name_list, std::forward<Tail>(tail)...);
    }

  private:
    std::string get_current_time_str() const;
    std::fstream fos_;
  };
  std::list<std::string> split_string_by_comma(std::string src_string);
}

#endif  // INCLUDED_LOGGER_HPP
