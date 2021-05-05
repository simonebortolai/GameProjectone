#include "misc.hpp"

void initScreen() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

void loop() {
    usleep(100000);
}
    

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}