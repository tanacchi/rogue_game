#include <rogue_game/rogue_game.hpp>
#include <map/text_map.hpp>
#include <map/map_writer.hpp>

int main(int argc, char** argv)
{
  try {
    const std::vector<std::string> arg_list{argv, argv + argc};
    const std::string text_map_filename{arg_list[1]};
    const std::vector<std::string> map_strings{map::read_map_strings(text_map_filename)};
    map::TextMap text_map{map_strings};
    std::cout << text_map << std::endl;
    LOG_VALUES(text_map);
    map::MapWriter map_writer{};
    map_writer(text_map);
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
