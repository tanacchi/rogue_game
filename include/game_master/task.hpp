#ifndef INCLUDED_TASK_HPP
#define INCLUDED_TASK_HPP

#include <cstdint>

enum class Task : std::uint8_t
{
  Show, Update, Perform, End
};

#endif  // INCLUDED_TASK_HPP
