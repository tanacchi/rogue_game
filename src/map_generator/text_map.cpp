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
  }
}
