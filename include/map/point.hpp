#ifndef INCLUDED_POINT_HPP
#define INCLUDED_POINT_HPP

#include <ostream>
#include <utility>

namespace map
{
  // マップ上での位置を表現する
  template<typename T>
  class Point
  {
  public:
    Point(T x = 0, T y = 0);
    template<typename U>
    Point(U x, U y)
      : x_{static_cast<T>(x)}, y_{static_cast<T>(y)}
    {
    }
    Point(const Point& point);
    template<typename U>
    Point(const Point<U>& point)
      : x_{static_cast<T>(point.get_x())},
        y_{static_cast<T>(point.get_y())}
    {
    }
    Point(Point&& point);
    const T get_x() const;
    const T get_y() const;
    Point& operator=(const Point& rls);
    Point& operator=(Point&& rls);
    const Point operator+(const Point& rhs) const;
    const Point& operator+=(const Point& rhs);
    bool operator==(const Point& rhs) const;
    bool operator<(const Point& rls) const;
    friend std::ostream& operator<<(std::ostream& os, const Point<int>& point);
  private:
    T x_;
    T y_;
  };
}

#endif  // INCLUDED_POINT_HPP
