#ifndef INCLUDED_TEXT_MAP_HPP
#define INCLUDED_TEXT_MAP_HPP

#include <vector>

#include <map/point.hpp>

struct TextMap {
  public:
    TextMap(const std::vector<std::string>& map_strings);
    const std::size_t width{};
    const std::size_t height{};
    const std::string text{};
    Point<std::size_t> index_to_point(std::size_t index) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const TextMap& text_map);

  private:
    const std::size_t get_width(const std::vector<std::string>& map_strings);
    const std::size_t get_height(const std::vector<std::string>& map_strings);
    const std::string get_text(const std::vector<std::string>& map_strings);
};

const std::vector<std::string> read_map_strings(const std::string& filename);

#endif  // INCLUDED_TEXT_MAP_HPP
