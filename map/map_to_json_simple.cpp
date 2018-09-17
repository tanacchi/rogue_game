#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

int main(int argc, char** argv)
{
  boost::property_tree::ptree map_data;
  map_data.put("Map.width", 30);
  map_data.put("Map.height", 10);
  boost::property_tree::ptree elem_list;
  for (int i{0}; i < 3; ++i) {
    boost::property_tree::ptree elem;
    elem.put("type", "horizontal_wall");
    elem_list.push_back(std::make_pair("", elem));
  }
  map_data.add_child("Map.elems", elem_list);

  boost::property_tree::write_json("tmp_sample_map.json", map_data);
  return 0;
}
