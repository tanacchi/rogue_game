#ifndef INCLUDED_MAP_READER_HPP
#define INCLUDED_MAP_READER_HPP

#include <boost/property_tree/ptree.hpp>

#include <map/map.hpp>

class MapReader
{
  public:
    Map operator()(std::string map_filename);
};

DungeonElemPtr gen_dungeon_elem(std::string type);
ItemPtr gen_item_elem(std::string type, boost::property_tree::ptree property);

#endif // INCLUDED_MAP_READER_HPP
