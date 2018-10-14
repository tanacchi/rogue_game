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
    std::fstream fos_;
  };
}

#endif  // INCLUDED_LOGGER_HPP
