#include "room.hpp"
#include <stdexcept>

#include <stdlib.h>     /* srand, rand */
#include <time.h>     /* time (per srand e rand) */


Room::Room(point size, int level) : Space2d(size) {
    generateRoom(level);
    generatePlatform();
}


void Room::generateRoom(int level) {
    int height = this->size.y;
    int width = this->size.x;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if ((row == 0 && col == 0) || (row == height-1 && col == 0) || (row == 0 && col == width-1) || (row == height-1 && col == width-1)) {
                point tmp {col, row};
                setPixel(tmp, (char)((int)'a' + level));
            } 
        }
    }
}

bool Room::isEmpty(point p) {
    if (p.x < 0 || p.x >= size.x || p.y < 0 || p.y >= size.y) {
        throw std::invalid_argument( "Qualche buon tempone chiede a Room se un pixel fori dallo schermo è voto" );
    } else if (getPixel(p) == ' ') {
        return true;  
    } 
    else {
        return false; 
    } 

}


void Room::generatePlatform() {
    srand(time(NULL));

    int startY = size.y - 4;
    int startX = 10 + ( rand() % (size.x - 35) );
    int length = 3 + (rand() % 12);

    for (int i = startX; i < startX + length; i++) {
        point tmp {i, startY};
        setPixel(tmp, '=');
    }
}


/*
bool Room::is_floor(int y) {
    if (*(*(content+y)) == '=')
        return true;
    else
        return false;
}
*/