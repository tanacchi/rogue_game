#include <debug/logger.hpp>

namespace debug
{
  Logger::Logger()
    : fos_{"log/text.log", std::ios::out}
  {
    fos_ << "Hello" << std::endl;
  }
}
