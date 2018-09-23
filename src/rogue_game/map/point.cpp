#include <map/point.hpp>

namespace map
{
  Point::Point(std::size_t x = 0, std::size_t y = 0)
    : x_{x}, y_{y}
  {
  }

  const std::size_t Point::get_x() const
  {
    return x_;
  }

  const std::size_t Point::get_y() const
  {
    return y_;
  }

  const Point& Point::operator+=(const Point& rhs)
  {
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
  }

  const Point& Point::operator+(const Point& rhs)
  {
    *this += rhs;
    return *this;
  }

}
