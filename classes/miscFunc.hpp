#ifndef MISCFUNC_HPP_INCLUDED
#define MISCFUNC_HPP_INCLUDED

#include <ncurses.h>
#include "./entities/bullet.hpp"
#include "./entities/livingentity.hpp"
#include "./entities/element.hpp"


struct bulletList {
    Bullet *value;
    bulletList *next;
};

typedef bulletList *pBullet;


struct monsterList {
    LivingEntity *value;
    monsterList *next;
};

typedef monsterList *pMonster;


struct bonusList {
    Element *value;
    bonusList *next;
};

typedef bonusList *pBonus;


struct allEntityList {
    LivingEntity *player;
    monsterList *headMonster;
    bulletList *headBullet;
    bonusList *headBonus;
};

typedef allEntityList *pEntity;


pBullet newBullet(pBullet list, Bullet * b);//nuovoSparo
pMonster newMonster(pMonster list, LivingEntity * b);//nuovoMostro
pBonus newBonus(pBonus list, Element * b);

pBullet removeBullet(pBullet list, Bullet * b);//eliminaSparo
pMonster removeMonster(pMonster list, LivingEntity * b);//eliminaMostro
pBonus removeBonus(pBonus list, Element * b);

#endif