#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  initscr();
  printw("Hello, ncurses.");
  refresh();
  sleep(3);
  endwin();
  return 0;
}
