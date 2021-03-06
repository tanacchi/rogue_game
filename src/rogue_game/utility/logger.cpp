#include <chrono>
#include <ctime>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

#include <utility/logger.hpp>
#include <utility/path.hpp>

std::fstream Logger::fos_{};

void Logger::init_log_file()
{
  namespace fs = boost::filesystem;
  const std::string log_file_name{get_current_time_str() + ".log"};
  const std::string symlink_path{log_dir + "latest.log"};

  if (!fs::exists(log_dir))
  {
    fs::create_directory(log_dir);
  }
  if (fs::exists(symlink_path))
  {
    fs::remove(symlink_path);
  }
  Logger::fos_.open(log_dir + log_file_name, std::ios::out);
  fs::create_symlink(log_file_name, symlink_path);
}

void Logger::log_with_name(std::list<std::string>&& name_list)
{
  if (!Logger::fos_.is_open()) init_log_file();
  fos_ << '\n'
    << "\t\t\t\t[" << name_list.front() << "]\n\n"<< std::endl;
}

void Logger::log_string(const std::string& str, char separate_char)
{
  if (!Logger::fos_.is_open()) init_log_file();
  std::string separator(str.length(), separate_char);
  fos_ << separator << '\n' << str << '\n' << separator << std::endl;
}

std::list<std::string> split_string_by_comma(std::string src_string)
{
  std::list<std::string> strings{};
  boost::split(strings, src_string, boost::is_any_of(", "),
      boost::algorithm::token_compress_on );
  return strings;
}

std::string get_current_time_str()
{
  auto now{std::chrono::system_clock::now()};
  auto time{std::chrono::system_clock::to_time_t(now)};
  char time_str[20];
  std::strftime(time_str, sizeof(time_str), "%F_%T",std::localtime(&time));
  return std::string{time_str};
}

