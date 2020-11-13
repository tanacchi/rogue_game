#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <ostream>

#include <utility/point.hpp>

class Character
{
  public:
    Character(Point<int> position = zero);
    const Point<int>& get_position() const;
    void set_position(const Point<int>& point);
    friend std::ostream& operator<<(std::ostream& os, const Character& character);
    std::size_t get_hit_point() const noexcept;
    void hit(std::size_t damage) noexcept;

  protected:
    Point<int> position_;
    std::size_t hit_point_;
};

#endif  // INCLUDED_CHARACTER_HPP
