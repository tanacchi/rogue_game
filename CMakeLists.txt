cmake_minimum_required(VERSION 3.5.1)

set(MAJOR 0)

execute_process(
  COMMAND git tag
  COMMAND wc --lines
  OUTPUT_VARIABLE MINOR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

if (${MINOR})
  execute_process(
    COMMAND git describe --abbrev=0
    OUTPUT_VARIABLE LATEST_RELEASE
    OUTPUT_STRIP_TRAILING_WHITESPACE)  
  execute_process(
    COMMAND git log ${LATEST_RELEASE}..origin/master --oneline --merges --first-parent origin/master
    COMMAND wc --lines
    OUTPUT_VARIABLE PATCH
    OUTPUT_STRIP_TRAILING_WHITESPACE)
else()
  execute_process(
    COMMAND git log --oneline --merges --first-parent origin/master
    COMMAND wc --lines
    OUTPUT_VARIABLE PATCH
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

project(
  rogue_game
  VERSION ${MAJOR}.${MINOR}.${PATCH}
  LANGUAGES CXX)

find_package(Boost REQUIRED
  system
  filesystem
)
find_package(Curses REQUIRED)

if (NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DDEBUG")

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(
  ${PROJECT_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${CURSES_INCLUDE_DIR}
)

link_directories(
  ${Boost_LIBRARY_DIRS}
  ${CURSES_LIBRARY_DIR}
)

set(${PROJECT_NAME}_CONFIGURE_DIR ${PROJECT_SOURCE_DIR}/config)
configure_file(
  ${${PROJECT_NAME}_CONFIGURE_DIR}/README.md.in
  ${PROJECT_SOURCE_DIR}/README.md)
configure_file(
  ${${PROJECT_NAME}_CONFIGURE_DIR}/path.hpp.in
  ${PROJECT_INCLUDE_DIR}/utility/path.hpp)

add_subdirectory(src)

# For terminal setting on WSL
if (CMAKE_HOST_SYSTEM MATCHES "^.*Microsoft$")
  message(STATUS "It's on Windows system")
endif()

# message(STATUS "*** dump start cmake variables ***")
# get_cmake_property(_variableNames VARIABLES)
# foreach(_variableName ${_variableNames})
        # message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
# message(STATUS "*** dump end ***")
