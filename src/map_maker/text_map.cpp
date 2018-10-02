#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

#include <map/text_map.hpp>

namespace map
{
  namespace generator
  {
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

    std::vector<std::string> read_map_strings(std::string filename)
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

    TextMap get_text_map_obj(std::vector<std::string> map_strings)
    {
      TextMap tm;
      for (auto row : map_strings) {
        tm.width = std::max(tm.width, row.length());
      }
      tm.height = map_strings.size();
      std::stringstream ss{};
      for (auto row : map_strings) {
        ss << std::setw(tm.width) << std::setfill(' ') << std::left << row;
      }
      tm.text = ss.str();
      return tm;
    }
  }
}
