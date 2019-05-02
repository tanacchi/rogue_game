#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <ostream>

#include <utility/logger.hpp>
#include <utility/point.hpp>

class Character
{
  public:
    Character(Point<int> position = zero);
    const Point<int>& get_position() const;
    void set_position(const Point<int>& point);
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

  protected:
    Point<int> position_;
    std::size_t hit_point_;
    std::size_t max_hit_point_;
};

#endif  // INCLUDED_CHARACTER_HPP
