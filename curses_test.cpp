#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  initscr();
  mvprintw(20, 15, "Hello, ncurses.");
  refresh();
  sleep(3);
  endwin();
  return 0;
}
