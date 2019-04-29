#ifndef INCLUDED_TASK_HPP
#define INCLUDED_TASK_HPP

#include <cstdint>

enum class Task : std::uint8_t
{
  Show, Input, Switch, Perform, End
};

#endif  // INCLUDED_TASK_HPP
