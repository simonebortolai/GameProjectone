#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED
//#include "bullet.hpp"
#include "livingentity.hpp"


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

/*
struct bulletList {
    Bullet *value;
    bulletList *next;
};


struct monsterList {
    LivingEntity *value;
    monsterList *next;
};

*/

struct allEntityList {
    LivingEntity *player;
    //monsterList *headMonster;
    //bulletList *headBullet;
};


void initScreen();
allEntityList * initEntity(point dimension);

#endif