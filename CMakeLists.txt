cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")

add_executable(rogue_game.out curses_test.cpp)
target_link_libraries(rogue_game.out ncurses)
