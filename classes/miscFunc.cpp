#include "miscFunc.hpp"


void initScreen() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}


allEntityList * initEntity(point dimension) {
    allEntityList * listOfAllEntity;

    struct point p {dimension.x/2, 2};

    listOfAllEntity->player = new LivingEntity(&p, '@', 100, 10);
}
    