#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <debug/logger.hpp>
#include <map/text_map.hpp>

namespace map
{
  TextMap::TextMap(const std::vector<std::string>& map_strings)
    : width{get_width(map_strings)},
      height{get_height(map_strings)},
      text{get_text(map_strings)}
  {
  }

  Point<std::size_t> TextMap::index_to_point(std::size_t index) const noexcept
  {
    return {index % width, index / width};
  }

  std::ostream& operator<<(std::ostream& os, const TextMap& text_map)
  {
    os << " { width : " << text_map.width  << " },"
      << " { height : " << text_map.height << "},\n"
      << " { text :\n";
    for (std::size_t i{0}; i < text_map.text.length(); i += text_map.width) {
      std::string row{text_map.text.substr(i, text_map.width)};
      os << row << '\n';
    }
    os << '}';
    return os;
  }

  const std::size_t TextMap::get_width(const std::vector<std::string>& map_strings)
  {
    const std::vector<std::string>::const_iterator longest_row =
      std::max_element(map_strings.begin(), map_strings.end(),
          [](const std::string& left, const std::string& right) {
          return left.length() < right.length();
          });
    return longest_row->length();
  }

  const std::size_t TextMap::get_height(const std::vector<std::string>& map_strings)
  {
    return map_strings.size();
  }

  const std::string TextMap::get_text(const std::vector<std::string>& map_strings)
  {
    std::stringstream ss{};
    for (auto row : map_strings) {
      ss << std::setw(width) << std::setfill(' ') << std::left << row;
    }
    return ss.str();
  }

  const std::vector<std::string> read_map_strings(const std::string& filename)
  {
    std::ifstream read_file{};
    read_file.open(filename, std::ios::in);

    std::vector<std::string> map_strings{};
    std::string input_buff{};
    for (std::size_t row{0}; !read_file.eof(); ++row) { // Range-based-for でも良くないか
      std::getline(read_file, input_buff);
      map_strings.emplace_back(input_buff);
    }
    return map_strings;
  }    
}
