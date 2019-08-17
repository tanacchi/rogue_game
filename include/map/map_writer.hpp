#ifndef INCLUDED_MAP_GENERATOR_HPP
#define INCLUDED_MAP_GENERATOR_HPP

#include <vector>
#include <boost/property_tree/ptree.hpp>

using ConfigType = boost::property_tree::ptree;

class TextMap;

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
