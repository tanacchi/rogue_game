#ifndef INCLUDED_ROGUE_GAME_HPP
#define INCLUDED_ROGUE_GAME_HPP

// #include <string_view>  // In C++17
#include <boost/filesystem.hpp>

#include <debug/logger.hpp>

const std::string map_dir{boost::filesystem::current_path().string() + "/map/"};
// constexpr std::string_view map_dir{boost::filesystem::current_path().string() + "/map/"};

#endif  // INCLUDED_ROGUE_GAME_HPP
