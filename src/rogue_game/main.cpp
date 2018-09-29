#include <rogue_game.hpp>

std::string key_to_str(KeyboardManager::KeyState key)
{
  switch (key) {
  case KeyboardManager::KeyState::Space:
    return "Space";
  case KeyboardManager::KeyState::Enter:
    return "Enter";
  case KeyboardManager::KeyState::Back:
    return "Back";
  case KeyboardManager::KeyState::Up:
    return "Up";
  case KeyboardManager::KeyState::Down:
    return "Down";
  case KeyboardManager::KeyState::Right:
    return "Right";
  case KeyboardManager::KeyState::Left:
    return "Left";
  default:
    return "Unknown";
  }
}

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  
  map::Map map = map::read_map(map_dir + "json/tmp_sample_map.json");
  map::MapDisplay md{5, 4, map.width, map.height};
  std::unique_ptr<KeyboardManager> km_ptr{new KeyboardManager};
  character::Player player{map::Point{10, 15}, std::move(km_ptr)};
  while (true) {
    md.show(map, player);
    refresh();
    player.update(map);
  }
  endwin();
  return 0;
}
