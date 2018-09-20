cmake_minimum_required(VERSION 3.5.1)

project(rogue_game
  VERSION 0.0.0
  LANGUAGES CXX
)
message(STATUS PROJECT_NAME: ${PROJECT_NAME})
message(STATUS ${PROJECT_NAME}_SOURCE_DIR: ${${PROJECT_NAME}_SOURCE_DIR})

set(CMAKE_CXX_COMPILER g++)
message(STATUS CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER})

set(CMAKE_CXX_FLAGS "-Wall")
message(STATUS CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS})

set(CMAKE_CXX_STANDARD 14)
message(STATUS CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD})

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
