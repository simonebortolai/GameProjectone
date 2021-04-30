#include <ncurses.h>
#include "misc.hpp"

void initScreen() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

allEntityList * initEntity(point dim) {
    allEntityList * listOfAllEntity;
    listOfAllEntity->player = new LivingEntity(1, dim.y/2, '@', 100, 10);
    //listOfAllEntity->headMonster = NULL;
    //listOfAllEntity->headBullet = NULL;
}
    