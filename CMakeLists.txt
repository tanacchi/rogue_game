cmake_minimum_required(VERSION 3.5.1)

add_definitions("-Wall --std=c++14")

add_executable(rogue_game.out curses_test.cpp)
target_link_libraries(rogue_game.out ncurses)
