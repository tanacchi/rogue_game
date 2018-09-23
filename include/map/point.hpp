#ifndef INCLUDED_POINT_HPP
#define INCLUDED_POINT_HPP

#include <cstddef>

namespace map
{
  class Point
  {
  public:
    Point(std::size_t x, std::size_t y);
    std::size_t get_x();
    std::size_t get_y();
    const Point& operator+=(const Point& rhs);
    const Point& operator+(const Point& rhs);
  private:
    std::size_t x_;
    std::size_t y_;
  };
}

#endif  // INCLUDED_POINT_HPP
