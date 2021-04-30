#include "miscFunc.hpp"


void initScreen() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}


void initEntity(allEntityList * allEntity, point dimension) {
    
    struct point p {dimension.x/2, 2};

    struct allEntityList temp {new LivingEntity(p, '@', 100, 10)};
    allEntity = &temp;
 
}
    