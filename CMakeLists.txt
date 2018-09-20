cmake_minimum_required(VERSION 3.5.1)

execute_process(
  COMMAND git tag
  COMMAND wc --lines
  OUTPUT_VARIABLE MAJOR
  OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS MAJOR: ${MAJOR})

if (${MAJOR})
  execute_process(
    COMMAND git describe --abbrev=0
    OUTPUT_VARIABLE LATEST_RELEASE
    OUTPUT_STRIP_TRAILING_WHITESPACE)  
  execute_process(
    COMMAND git log origin/master..${LATEST_RELEASE} --oneline --merges --first-parent origin/master
    COMMAND wc --lines
    OUTPUT_VARIABLE MINOR
    OUTPUT_STRIP_TRAILING_WHITESPACE)
else()
  execute_process(
    COMMAND git log --oneline --merges --first-parent origin/master
    COMMAND wc --lines
    OUTPUT_VARIABLE MINOR
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()
message(STATUS MINOR: ${MINOR})

project(
  rogue_game
  VERSION ${MAJOR}.${MINOR}
  LANGUAGES CXX)
message(STATUS PROJECT_NAME: ${PROJECT_NAME})
message(STATUS ${PROJECT_NAME}_SOURCE_DIR: ${${PROJECT_NAME}_SOURCE_DIR})

set(CMAKE_CXX_COMPILER g++)
message(STATUS CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER})

set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")
message(STATUS CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS})

# set(CMAKE_CXX_STANDARD 14)
# message(STATUS CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD})

include_directories(
  include
)

add_executable(${PROJECT_NAME}.out
  src/main.cpp
  src/keyboard_manager.cpp
  src/display_panel.cpp
  src/map_display.cpp
  src/map_elem.cpp
  src/map.cpp
)
target_link_libraries(${PROJECT_NAME}.out ncurses)

message(STATUS "============ CMake Variables =============")
get_cmake_property(_variableNames VARIABLES)
foreach(_variableName ${_variableNames})
  message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
message(STATUS "==========================================")
