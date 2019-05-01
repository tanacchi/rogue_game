#ifndef INCLUDED_CHARACTER_HPP
#define INCLUDED_CHARACTER_HPP

#include <ostream>

#include <debug/logger.hpp>
#include <map/point.hpp>

class Character
{
  public:
    Character(Point<int> position = zero);
    const Point<int>& get_position() const;
    void set_position(const Point<int>& point);
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

  protected:
    Point<int> position_;
};

#endif  // INCLUDED_CHARACTER_HPP
