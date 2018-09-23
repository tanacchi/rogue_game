#ifndef INCLUDED_POINT_HPP
#define INCLUDED_POINT_HPP

namespace map
{
  class Point
  {
  public:
    Point(int x, int y);
    const int get_x() const;
    const int get_y() const;
    const Point& operator+=(const Point& rhs);
    const Point& operator+(const Point& rhs);
  private:
    int x_;
    int y_;
  };
}

#endif  // INCLUDED_POINT_HPP
