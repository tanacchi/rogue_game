#ifndef INCLUDED_MAP_READER_HPP
#define INCLUDED_MAP_READER_HPP

#include <map/map.hpp>

namespace map
{
  class MapReader
  {
  public:
    Map operator()(std::string map_filename);
  };
}

#endif // INCLUDED_MAP_READER_HPP
