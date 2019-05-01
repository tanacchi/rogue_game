#ifndef INCLUDED_MAP_ELEM_HPP
#define INCLUDED_MAP_ELEM_HPP

#include <ostream>

class MapElem {
  public:
    MapElem(std::string type);
    MapElem(const MapElem& rhs);
    MapElem(MapElem&& rhs) noexcept;
    virtual ~MapElem() = default;
    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const MapElem& map_elem);

    const std::string type;
    const char symbol;
};

const char get_symbol(const std::string);

#endif  // INCLUDED_MAP_ELEM_HPP
