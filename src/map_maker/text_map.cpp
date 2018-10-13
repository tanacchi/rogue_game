#include <algorithm>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

#include <map/text_map.hpp>

namespace map
{
  namespace generator
  {
    TextMap::TextMap(const std::vector<std::string>& map_strings)
      : width{get_width(map_strings)},
        height{get_height(map_strings)},
        text{get_text(map_strings)}
    {
    }

    void TextMap::show() const
    {
      std::cout << "width:  [" << width  << "]\n"
                << "height: [" << height << "]\n"
                << "text: " << std::endl;
      for (std::size_t i{0}; i < text.length(); i += width) {
        std::string row{text.substr(i, width)};
        std::cout << row << std::endl;
      }
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
      for (std::size_t row{0}; !read_file.eof(); ++row) {
        std::getline(read_file, input_buff);
        map_strings.emplace_back(input_buff);
      }
      return map_strings;
    }    
  }
}
