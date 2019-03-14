#ifndef INCLUDED_PLAYER_DISPLAY_HPP
#define INCLUDED_PLAYER_DISPLAY_HPP

#include <character/player.hpp>
#include <display/display_panel.hpp>

// プレイヤーのステータスを表示する
// ただしマップ上のプレイヤーはウィンドウが違うので MapDisplay が表示してる
class PlayerDisplay : public DisplayPanel
{
public:
  PlayerDisplay(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
  ~PlayerDisplay()
  {
    LOG_STRING("PlayerDisplay is destructing now.");
  }

  void show(const character::Player& player);
};

#endif  // INCLUDED_PLAYER_DISPLAY_HPP
