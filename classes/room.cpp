#include "room.hpp"


Room::Room(point size, int level) : Space2d(size) {
    generateRoom(level);
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
    if (getPixel(p) == ' ') {
        return true;  
    } 
    else {
        return false; 
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