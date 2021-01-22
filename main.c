/**
 * Copyright 2021 David Thompson
 */
#include <ncurses.h>

/* red --> orange */
/* dark           */
/*  |             */
/*  |             */
/*  v             */
/* light          */
int colors[4][4] = {
  {124, 166, 202, 208},
  {203, 167, 172, 214},
  {217, 174, 173, 178},
  {224, 181, 180, 223}
};

int main() {
  int r = 0;
  int c = 0;
  int running = 1;
  /* Make an empty screen */
  initscr();
  /* Enable keypad mode, which allows arrow key detection */
  /* see: https://stackoverflow.com/questions/43923546/proper-way-of-catching-controlkey-in-ncurses */
  keypad(stdscr, TRUE);
  /* Enable color support */
  start_color();
  do {
    /* Override the color pair #1 to have
       foreground and background as the selected color */
    init_pair(1, colors[r][c], colors[r][c]);
    /* Set the background to the bright orange color pair */
    bkgd(COLOR_PAIR(1));
    /* Update the window */
    refresh();

    /* Wait for character to be pressed */
    int pressed = getch();
    move(0, 0);

    switch (pressed) {
    case 'h':
    case 'H':
    case KEY_LEFT:
      c--;
      if (c < 0)
        c = 0;
      break;
    case 'j':
    case 'J':
    case KEY_DOWN:
      r++;
      if (r >= 4)
        r = 3;
      break;
    case 'k':
    case 'K':
    case KEY_UP:
      r--;
      if (r < 0)
        r = 0;
      break;
    case 'l':
    case 'L':
    case KEY_RIGHT:
      c++;
      if (c >= 4)
        c = 3;
      break;
    case 'q':
    case 'Q':
      running = 0;
      break;
    }
  } while (running);
  endwin();
  return 0;
}
