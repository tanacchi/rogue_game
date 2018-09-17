cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")

include_directories(
  include
)

add_executable(rogue_game.out
  src/keyboard_manager.cpp
  src/display_panel.cpp
)
target_link_libraries(rogue_game.out ncurses)
