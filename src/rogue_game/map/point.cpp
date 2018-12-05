#include <map/point.hpp>

namespace map
{
  template<typename T>
  Point::Point(T x, T y)
    : x_{x}, y_{y}
  {
  }

  template<typename T>
  Point::Point(const Point& point)
    : x_{point.x_},
      y_{point.y_}
  {
  }

  template<typename T>
  Point::Point(Point&& point)
    : x_{std::move(point.x_)},
      y_{std::move(point.y_)}
  {
  }

  template<typename T>
  const T Point::get_x() const
  {
    return x_;
  }

  template<typename T>
  const T Point::get_y() const
  {
    return y_;
  }

  Point& Point::operator=(const Point& rls)
  {
    x_ = rls.x_;
    y_ = rls.y_;
    return *this;
  }

  Point& Point::operator=(Point&& rls)
  {
    x_ = std::move(rls.x_);
    y_ = std::move(rls.y_);
    return *this;
  }

  const Point Point::operator+(const Point& rhs) const
  {
    return {x_ + rhs.x_, y_ + rhs.y_};
  }

  const Point& Point::operator+=(const Point& rhs)
  {
    *this = *this + rhs;
    return *this;
  }

  bool Point::operator==(const Point& rhs) const
  {
    return x_ == rhs.x_ && y_ == rhs.y_;
  }

  // 現状、比較演算は原点からの距離で判定
  bool Point::operator<(const Point& rls) const
  {
    return (x_*x_ + y_*y_) < (rls.x_*rls.x_ + rls.y_*rls.y_);
  }

  std::ostream& operator<<(std::ostream& os, const Point& point)
  {
    os << "{ x : " << point.x_ << " }, { y : " << point.y_ << " }";
    return os;
  }
}
