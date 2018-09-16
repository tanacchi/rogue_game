#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  initscr();
  keypad(stdscr, TRUE);

  int count{0};
  while (true) {
    if (getch()) {
      ++count;
    }
    mvprintw(20, 15, "Hello, ncurses. [%d]\n", count);
    refresh();
  }
  endwin();
  return 0;
}
