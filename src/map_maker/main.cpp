#include <rogue_game/rogue_game.hpp>
#include <map/text_map.hpp>
#include <map/map_generator.hpp>

int main(int argc, char** argv)
{
  try {
    const std::vector<std::string> arg_list{argv, argv + argc};
    const std::string text_map_filname{arg_list[1]};
    const std::vector<std::string> map_strings{map::generator::read_map_strings(text_map_filname)};
    map::generator::TextMap text_map{map::generator::get_text_map_obj(map_strings)};
    text_map.show();
    map::generator::MapGenerator map_generator{text_map, "ver_0.1.0.0_map"};
    map_generator.set_configs();
    map_generator.write_json_map();
  }
  catch (const std::logic_error& e) {
    std::cout << e.what() << std::endl;
    std::cout << "[Usage]: argv[1]: text_map_file" << std::endl;
    return -1;
  }
  return 0;
}
