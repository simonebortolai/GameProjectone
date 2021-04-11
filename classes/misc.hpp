#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED


#include "people.hpp"

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


struct bulletList {
    Bullet *value;
    bulletList *next;
};

struct monsterList {
    LivingEntity *value;
    monsterList *next;
};

struct entityList {
    Entity *value;
    entityList *next;
};


struct allEntity {
    LivingEntity *player;
    monsterList *head;
    bulletList *head;
}


typedef entityList *pEntityList;


#endif
