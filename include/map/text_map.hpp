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

    std::vector<std::string> read_map_strings(std::string filename);
    TextMap get_text_map_obj(std::vector<std::string> map_strings);
  }
}

#endif  // INCLUDED_TEXT_MAP_HPP
