#include <cmath>
#include <utility/point.hpp>

template<typename T>
Point<T>::Point(T x, T y)
  : x_{x}, y_{y}
{
}

template<typename T>
Point<T>::Point(const Point<T>& point)
  : x_{point.x_}
  , y_{point.y_}
{
}

template<typename T>
Point<T>::Point(Point<T>&& point)
  : x_{std::move(point.x_)}
  , y_{std::move(point.y_)}
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
Point<T>& Point<T>::operator=(const Point<T>& rhs)
{
  x_ = rhs.x_;
  y_ = rhs.y_;
  return *this;
}

template<typename T>
Point<T>& Point<T>::operator=(Point<T>&& rhs)
{
  x_ = std::move(rhs.x_);
  y_ = std::move(rhs.y_);
  return *this;
}

template<typename T>
const Point<T> Point<T>::operator+(const Point<T>& rhs) const
{
  return {x_ + rhs.x_, y_ + rhs.y_};
}

template<typename T>
const Point<T> Point<T>::operator-(const Point<T>& rhs) const
{
  return {x_ - rhs.x_, y_ - rhs.y_};
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

template<typename T>
bool Point<T>::operator!=(const Point<T>& rhs) const
{
  return !(*this == rhs);
}

template<typename T>
bool Point<T>::operator<(const Point<T>& rhs) const
{
  auto lhs_distance = x_*x_ + y_*y_, rhs_distance =rhs.x_*rhs.x_ + rhs.y_*rhs.y_;
  if (lhs_distance == rhs_distance)
    return x_ < rhs.x_;
  else
    return lhs_distance < rhs_distance;
}

template<typename T>
Point<T>::operator bool() const noexcept
{
  return !(x_ == 0 && y_ == 0);
}

float norm(const Point<int>& point)
{
  const auto x{static_cast<float>(point.x_)};
  const auto y{static_cast<float>(point.y_)};
  return sqrt(x*x + y*y);
}

float norm(const Point<int>&& point)
{
  const auto x{static_cast<float>(point.x_)};
  const auto y{static_cast<float>(point.y_)};
  return sqrt(x*x + y*y);
}

std::ostream& operator<<(std::ostream& os, const Point<int>& point)
{
  os << "{ x : " << point.x_ << " }, { y : " << point.y_ << " }";
  return os;
}

template class Point<int>;
template class Point<std::size_t>;
