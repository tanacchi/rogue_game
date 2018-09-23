#include <map/point.hpp>

namespace map
{
  Point::Point(int x = 0, int y = 0)
    : x_{x}, y_{y}
  {
  }

  const int Point::get_x() const
  {
    return x_;
  }

  const int Point::get_y() const
  {
    return y_;
  }

  const Point Point::operator+(const Point& rhs) const
  {
    return Point{x_ + rhs.x_, y_ + rhs.y_};
  }

  const Point& Point::operator+=(const Point& rhs)
  {
    *this = *this + rhs;
    return *this;
  }

}
