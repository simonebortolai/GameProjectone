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
    usleep(50);
}
    

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}


int random(int min, int max) {
    return min + (rand() % (max - min));
}