cmake_minimum_required(VERSION 3.5.1)

project(ROGUE_GAME
  VERSION 0.0.0
  LANGUAGES CXX
)
message(STATUS ROGUE_GAME_SOURCE_DIR: ${ROGUE_GAME_SOURCE_DIR})

set(CMAKE_CXX_COMPILER g++)
message(STATUS CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER})

set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")
message(STATUS CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS})

include_directories(
  include
)

add_executable(rogue_game.out
  src/main.cpp
  src/keyboard_manager.cpp
  src/display_panel.cpp
  src/map_display.cpp
  src/map_elem.cpp
  src/map.cpp
)
target_link_libraries(rogue_game.out ncurses)
