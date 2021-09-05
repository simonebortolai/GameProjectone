#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp"
#include "space2d.hpp"
#include <stdlib.h>     /* srand, rand */
#include "miscFunc.hpp"
#include <iostream>


/*
serve a tenere le informazione per generare le piattaforme di una stanza:
    altezza, posizione e lunghezza della piattaforma precedente (-1 se non esistente), spazio
    da tenere libero ai lati e lunghezza massima e minima della piattaforma 
    Le raggruppo per non dover passare 6 parametri alla funzione che genera
*/
struct platformInfo {
    int y; 
    int lastX;
    int lastLen;
    int sideSpace;
    int minLen; 
    int maxLen;
};


class Room : public Space2d {
    protected:
        int level;
        void generateRoom(int level);
    
        void generatePlatform(platformInfo & info);
        void generateAllPlatform(int n, int y_span, platformInfo & info);
        void drawPlatform(point start, int len);

    public:
        Room(point size, int level);
        bool isEmpty(point p);
        bool isFloor(point p);
        pMonster generateEnemies(pMonster head, point offset);
        pBonus generateBonus(pBonus head, point offset);

        //get methods
        int getLevel();
        char getChar(point pos);

};


#endif