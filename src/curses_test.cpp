#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  
  int count{0};
  while (true) {
    char input;
    if (input = getch()) {
      ++count;
    }
    mvprintw(20, 15, "Hello, ncurses. [%d]\n", count);
    mvprintw(21, 15, "Input char: [%c]\n", (char)input);
    refresh();
  }
  endwin();
  return 0;
}
