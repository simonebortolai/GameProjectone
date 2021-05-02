
#include "room.hpp"


//simo/ceci, create 3 prototipi di stanze grandezza {23, 79}
/*
char ** room1 = ["    ",
                 "    "];
char ** room2 = ["    ",
                 "    "];
char ** room3 = ["    ",
                 "    "];
*/


Room::Room(point dimension, int level) {
    this->dimension = dimension;
    generateRoom(level);
}


char** Room::getContent() {
    return this->content;
}

void Room::generateRoom(int level) {
    int height = this->dimension.y;
    int width = this->dimension.x;

    char** start = new char * [height];
    for (int row = 0; row < height; row++) {
        *(start+row) = new char [width];
        for (int col = 0; col < width; col++) {
            if ((row == 0 && col == 0) || (row == height-1 && col == 0) || (row == 0 && col == width-1) || (row == height-1 && col == width-1)) {
                *(*(start+row) + col) = (char)((int)'a' + level);
            } 
            else {
                *(*(start+row) + col) = ' ';
            }
        }
    }
    this->content = start;
}

bool Room::isEmpty(point p) {
    if (*(*(content+p.y)+p.x) == ' ') {
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