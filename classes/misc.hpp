#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED

#include <ncurses.h>


struct point {
    int x;
    int y;
};


struct boxPoints {
    int x;
    int y;
    int width;
    int height;
};

void initScreen();
void loop();
int max(int a, int b);




#endif