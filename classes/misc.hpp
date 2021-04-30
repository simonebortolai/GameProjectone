#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED

#include <ncurses.h>


struct point {
    int x;
    int y;
};


struct boxPoints {
    int startX;
    int startY;
    int width;
    int height;
};

void initScreen();
void loop();


#endif