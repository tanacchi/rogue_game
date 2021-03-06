#include <iostream>

#include <utility/logger.hpp>
#include <map/map_writer.hpp>
#include <map/text_map.hpp>

int main(int argc, char** argv)
{
  try
  {
    const std::vector<std::string> arg_list{argv, argv + argc};
    const std::string text_map_filename{arg_list[1]};
    const std::vector<std::string> map_strings{read_map_strings(text_map_filename)};
    TextMap text_map{map_strings};
    std::cout << text_map << std::endl;
    LOG_VALUES(text_map);
    MapWriter map_writer{};
    map_writer(text_map);
  }
  catch (const std::logic_error& e)
  {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
