#include <debug/logger.hpp>

namespace debug
{
  Logger::Logger()
    : fos_{"log/test.log", std::ios::out}
  {
    fos_ << "Hello" << std::endl;
  }
}
