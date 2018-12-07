#include <map/point.hpp>

namespace map
{
  template<typename T>
  Point<T>::Point(T x, T y)
    : x_{x}, y_{y}
  {
  }

  template<typename T>
  Point<T>::Point(const Point<T>& point)
    : x_{point.x_},
      y_{point.y_}
  {
  }

  template<typename T>
  Point<T>::Point(Point<T>&& point)
    : x_{std::move(point.x_)},
      y_{std::move(point.y_)}
  {
  }

  template<typename T>
  const T Point<T>::get_x() const
  {
    return x_;
  }

  template<typename T>
  const T Point<T>::get_y() const
  {
    return y_;
  }

  template<typename T>
  Point<T>& Point<T>::operator=(const Point<T>& rls)
  {
    x_ = rls.x_;
    y_ = rls.y_;
    return *this;
  }

  template<typename T>
  Point<T>& Point<T>::operator=(Point<T>&& rls)
  {
    x_ = std::move(rls.x_);
    y_ = std::move(rls.y_);
    return *this;
  }

  template<typename T>
  const Point<T> Point<T>::operator+(const Point<T>& rhs) const
  {
    return {x_ + rhs.x_, y_ + rhs.y_};
  }

  template<typename T>
  const Point<T>& Point<T>::operator+=(const Point<T>& rhs)
  {
    *this = *this + rhs;
    return *this;
  }

  template<typename T>
  bool Point<T>::operator==(const Point<T>& rhs) const
  {
    return x_ == rhs.x_ && y_ == rhs.y_;
  }

  // 現状、比較演算は原点からの距離で判定
  template<typename T>
  bool Point<T>::operator<(const Point<T>& rls) const
  {
    return (x_*x_ + y_*y_) < (rls.x_*rls.x_ + rls.y_*rls.y_);
  }

  std::ostream& operator<<(std::ostream& os, const Point<int>& point)
  {
    os << "{ x : " << point.x_ << " }, { y : " << point.y_ << " }";
    return os;
  }

  template class Point<int>;
  template class Point<std::size_t>;
}
