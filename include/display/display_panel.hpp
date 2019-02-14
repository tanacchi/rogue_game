#ifndef INCLUDED_DISPLAY_PANEL_HPP
#define INCLUDED_DISPLAY_PANEL_HPP

#include <memory>
#include <ncurses.h>

// 画面表示系クラスの基底
class DisplayPanel
{
public:
  DisplayPanel(std::size_t x, std::size_t y, std::size_t width, std::size_t height);

  // ポリモーフィックな使い方をするつもりがないので virtual にしてない
  ~DisplayPanel();
protected:
  // ncurses でウィンドウを扱うためのオブジェクト
  std::unique_ptr<WINDOW> win_;
  static bool has_initialized_;
};

#endif  // INCLUDED_DISPLAY_PANEL_HPP
