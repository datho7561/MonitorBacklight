#include <ncurses.h>

/* In a 256 color terminal, this represents a fairly bright orange color */
#define BRIGHT_ORANGE 202
#define LIGHT_ORANGE 215
#define BG_COLOR_IN_USE LIGHT_ORANGE

int main() {
  /* Make an empty screen */
  initscr();
  /* Enable color support */
  start_color();
  /* Override the color pair #1 to have
     foreground and background as bright orange */
  init_pair(1, BG_COLOR_IN_USE, BG_COLOR_IN_USE);
  /* Set the background to the bright orange color pair */
  bkgd(COLOR_PAIR(1));
  /* Update the window */
  refresh();

  /* Wait for any character to be pressed */
  getch();
  endwin();
  return 0;
}
