#ifndef INCLUDED_MAP_GENERATOR_HPP
#define INCLUDED_MAP_GENERATOR_HPP

#include <functional>
#include <map>
#include <stdexcept>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <map/map.hpp>
#include <map/text_map.hpp>

using ConfigType = boost::property_tree::ptree;

class MapWriter
{
  public:
    void set_configs(const TextMap& text_map, std::vector<ConfigType>& dungeon_configs, std::vector<ConfigType>& item_configs);
    void write_json_map(const TextMap& text_map,
                        const std::vector<ConfigType>& dungeon_configs,
                        const std::vector<ConfigType>& item_configs,
                        const std::string& output_filename) const;
    void operator()(const TextMap& text_map, const std::string& output_filename = "tmp_sample_map");
};

#endif  // INCLUDED_MAP_GENERATOR_HPP
