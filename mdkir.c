#include <unistd.h>
#include <ncurses.h>
#include "mdkir.h"

void draw_kir(int);

int main() {
  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, TRUE);
  leaveok(stdscr, TRUE);
  scrollok(stdscr, FALSE);

  for (int x = 0; x < COLS; x++) {
    draw_kir(x);
    refresh();
    usleep(20000);
  }

  mvcur(0, COLS - 1, LINES - 1, 0);
  endwin();

  return 0;
}

void draw_kir(int x) {
  const char kir[33][42] = {
    KSTR001, KSTR002, KSTR003, KSTR004, KSTR005, KSTR006, KSTR007, KSTR008,
    KSTR009, KSTR010, KSTR011, KSTR012, KSTR013, KSTR014, KSTR015, KSTR016,
    KSTR017, KSTR018, KSTR019, KSTR020, KSTR021, KSTR022, KSTR023, KSTR024,
    KSTR025, KSTR026, KSTR027, KSTR028, KSTR029, KSTR030, KSTR031, KSTR032,
    KSTR033
  };

  const char brows[3][42] = {
    KSTR113, KSTR114, KSTR115
  };

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 41; j++) {
      char ch = kir[i][j];

      if (x % 5 == 0 && i >= 12 && i <= 14) {
        ch = brows[i - 12][j];
      }

      mvaddch((LINES-33) / 2 + i, j + x, ch);
    }
  }
}
