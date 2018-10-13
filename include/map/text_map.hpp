#ifndef INCLUDED_TEXT_MAP_HPP
#define INCLUDED_TEXT_MAP_HPP

#include <iostream>

namespace map
{
  namespace generator
  {
    struct TextMap {
    public:
      TextMap(const std::vector<std::string>& map_strings);
      std::size_t width{};
      std::size_t height{};
      std::string text{};

      void show() const;
    private:
      const std::size_t get_width(const std::vector<std::string>& map_strings);
      const std::size_t get_height(const std::vector<std::string>& map_strings);
      const std::string get_text(const std::vector<std::string>& map_strings);
    };

    const std::vector<std::string> read_map_strings(const std::string& filename);
  }
}

#endif  // INCLUDED_TEXT_MAP_HPP
