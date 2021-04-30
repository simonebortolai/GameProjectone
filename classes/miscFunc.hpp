#include <ncurses.h>
//#include "bullet.hpp"
#include "livingentity.hpp"

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