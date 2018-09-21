cmake_minimum_required(VERSION 3.5.1)

execute_process(
  COMMAND git tag
  COMMAND wc --lines
  OUTPUT_VARIABLE MAJOR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

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

project(
  rogue_game
  VERSION ${MAJOR}.${MINOR}
  LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")
# set(CMAKE_CXX_STANDARD 14)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(
  ${PROJECT_INCLUDE_DIR}
)

set(${PROJECT_NAME}_CONFIGURE_DIR ${PROJECT_SOURCE_DIR}/config)
configure_file(
  ${${PROJECT_NAME}_CONFIGURE_DIR}/README.md.in
  ${PROJECT_SOURCE_DIR}/README.md)

configure_file(
  ${${PROJECT_NAME}_CONFIGURE_DIR}/${PROJECT_NAME}.hpp.in
  ${PROJECT_INCLUDE_DIR}/${PROJECT_NAME}.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*)
add_executable(${PROJECT_NAME}.out
  ${${PROJECT_NAME}_SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME}.out ncurses)

message(STATUS "============ CMake Variables =============")
get_cmake_property(_variableNames VARIABLES)
foreach(_variableName ${_variableNames})
  message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
message(STATUS "==========================================")
