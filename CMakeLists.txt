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

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")
# set(CMAKE_CXX_STANDARD 14)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(
  ${PROJECT_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
)

link_directories(
  ${Boost_LIBRARY_DIRS}
)

set(${PROJECT_NAME}_CONFIGURE_DIR ${PROJECT_SOURCE_DIR}/config)
configure_file(
  ${${PROJECT_NAME}_CONFIGURE_DIR}/README.md.in
  ${PROJECT_SOURCE_DIR}/README.md)

add_subdirectory(src)
