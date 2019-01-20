#include <rogue_game/rogue_game.hpp>
#include <rogue_game/game_master.hpp>

#include <character/character.hpp>

// Log test

#include <dungeon/door.hpp>
#include <dungeon/floor.hpp>
#include <dungeon/horizontal_wall.hpp>
#include <dungeon/none.hpp>
#include <dungeon/path.hpp>
#include <dungeon/vertical_wall.hpp>

#include <item/gold.hpp>

//

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();


  // Log test

  dungeon::Door door{};
  dungeon::Floor floor{};
  dungeon::HorizontalWall horizontal_wall{};
  dungeon::None none{};
  dungeon::Path path{};
  dungeon::VerticalWall vertical_wall{};

  LOG_VALUES(door, floor, horizontal_wall, none, path, vertical_wall);

  item::Gold gold{};

  LOG_VALUES(gold);
  
  //

  GameMaster master{};
  while (true) {
    master.update();
  }
  return 0;
}
