#ifndef INCLUDED_TEXT_MAP_HPP
#define INCLUDED_TEXT_MAP_HPP

#include <iostream>

namespace map
{
  namespace generator
  {
    struct TextMap {
      std::size_t width{};
      std::size_t height{};
      std::string text{};

      void show() const;
    };
  }
}

#endif  // INCLUDED_TEXT_MAP_HPP
