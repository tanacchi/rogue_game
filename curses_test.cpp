#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  char str[10];

  initscr();
  keypad(stdscr, TRUE);

  mvprintw(20, 15, "Hello, ncurses.\n");
  printw(" > ");
  while(getstr(str));
  mvprintw(22, 3, str);
  refresh();
  sleep(3);
  endwin();
  return 0;
}
