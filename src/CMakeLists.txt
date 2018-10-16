set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE ROGUE_GAME_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/rogue_game/*)

add_executable(${PROJECT_NAME}.out
  rogue_game.cpp
  ${ROGUE_GAME_SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME}.out ncurses)

add_executable(map_maker.out
  map_maker.cpp
  ${ROGUE_GAME_SOURCE_FILES}
)
target_link_libraries(map_maker.out ncurses)
