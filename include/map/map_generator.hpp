#ifndef INCLUDED_MAP_GENERATOR_HPP
#define INCLUDED_MAP_GENERATOR_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <functional>

#include <map/text_map.hpp>

namespace map
{
  namespace generator
  {
    class MapGenerator
    {
    public:
      MapGenerator(const TextMap& text_map, std::string output_filename = "tmp_sample_map");
      void set_elem_config_table();
      void set_configs();
      void write_json_map() const;
    private:
      const TextMap text_map_;
      const std::string output_filename_;
      std::map<char, std::function<void(std::size_t index)> > elem_config_table_;
      std::vector<boost::property_tree::ptree> dungeon_configs_;
      std::vector<boost::property_tree::ptree> item_configs_;
    };
  }
}

#endif  // INCLUDED_MAP_GENERATOR_HPP
