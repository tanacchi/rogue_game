#ifndef INCLUDED_POINT_HPP
#define INCLUDED_POINT_HPP

#include <ostream>
#include <utility>

namespace map
{
  // マップ上での位置を表現する
  class Point
  {
  public:
    Point(int x = 0, int y = 0);
    Point(const Point& point);
    Point(Point&& point);
    const int get_x() const;
    const int get_y() const;
    Point& operator=(const Point& rls);
    Point& operator=(Point&& rls);
    const Point operator+(const Point& rhs) const;
    const Point& operator+=(const Point& rhs);
    bool operator==(const Point& rhs) const;
    bool operator<(const Point& rls) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
  private:
    int x_;
    int y_;
  };
}

#endif  // INCLUDED_POINT_HPP
