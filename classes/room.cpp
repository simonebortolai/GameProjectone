#include "room.hpp"
#include <stdexcept>

#include <stdlib.h>     /* srand, rand */

#include <string>


Room::Room(point size, int level) : Space2d(size) {
    generateRoom(level);
}


void Room::generateRoom(int level) {
    //we can remove it
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

    platformInfo info;
    info.y = 4; 
    info.lastX = -1;
    info.lastLen = -1;
    info.sideSpace = 7;
    info.minLen = 7; 
    info.maxLen = 30;
    generateAllPlatform(4, 5, info);
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


void Room::drawPlatform(point start, int len) {
    for (int i = 0; i < len; i++) {
        point tmp {start.x + i, start.y};
        setPixel(tmp, '=');
    }
}


void Room::generatePlatform(platformInfo & info) {
    point start {-1, size.y - info.y};
    bool destra = true;
    int length = info.minLen + (rand() % (info.maxLen - info.minLen));
    
    /* controllo che la lunghezza non sia troppa da ambe le parti */
    if (info.lastX != -1 && (info.lastX - length < info.sideSpace && info.lastX + info.lastLen + length > size.x - info.sideSpace) ) {
        length = max(info.lastX - info.sideSpace, (size.x - info.sideSpace) - (info.lastX + info.lastLen));
    }

    /* Decide se randomizzare x, o cacciarlo a sinistra o a destra della scorsa piattaforma */
    if (info.lastX == -1) {
        start.x = info.sideSpace + ( rand() % (size.x - (info.sideSpace*2) - length) );
    } else {
        if (info.lastX - length < info.sideSpace) start.x = info.lastX + info.lastLen;
        else if (info.lastX + info.lastLen + length > size.x- info.sideSpace) start.x = info.lastX;
        else {
            int choiche = rand() % 2;
            start.x = info.lastX*(1-choiche) + (info.lastX + info.lastLen)*(choiche);    //giochetto matematico
        }


        if (info.lastX == start.x) destra = false;    

        //TEMPORANEO
        if ( (start.x - length < 7 && !destra) || (start.x + length > size.x - 7   && destra)) {
            std::string a = "("  + std::to_string(start.x) + ", " + std::to_string(start.y) + ")\ncon length: " + std::to_string(length) + "\nlastX:" + std::to_string(info.lastX) + "    lastLen: " + std::to_string(info.lastLen) + "\ndestra:" + std::to_string(destra) + "\n start.x - length < 7:" + std::to_string(start.x - length < 7);
            throw std::runtime_error(std::string("Bad platform") + a);
        }
    }

    if (destra) {
        drawPlatform(start, length);
    } else {
        start.x = start.x - length;
        drawPlatform(start, length);
    }

    info.lastX = start.x;
    info.lastLen = length;
    
}


void Room::generateAllPlatform(int n, int y_span, platformInfo & info) {
    for (int i = 0; i < n; i++) {
        generatePlatform(info);
        info.y += y_span;
        if (info.lastX == -1) break;
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