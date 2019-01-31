#ifndef INCLUDED_ROGUE_GAME_HPP
#define INCLUDED_ROGUE_GAME_HPP

#include <keyboard/key_manager.hpp>
#include <display/map_display.hpp>
#include <display/player_display.hpp>
#include <debug/logger.hpp>
#include <boost/filesystem.hpp>

const std::string map_dir{boost::filesystem::current_path().string() + "/map/"};

#endif  // INCLUDED_ROGUE_GAME_HPP
