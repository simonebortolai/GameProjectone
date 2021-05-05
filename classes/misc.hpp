#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */


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

struct roomPoint {
    int nRoom;
    int x;
    int y;
};

void initScreen();
void loop();



/* General purpouse functionz :) */
int max(int a, int b);
int random(int min, int max);




#endif