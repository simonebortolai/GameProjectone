#ifndef MISCFUNC_HPP_INCLUDED
#define MISCFUNC_HPP_INCLUDED

#include "./entities/bullet.hpp"
#include "./entities/livingentity.hpp"


struct bulletList {
    Bullet *value;
    bulletList *next;
};


struct monsterList {
    LivingEntity *value;
    monsterList *next;
};


struct allEntityList {
    LivingEntity *player;
    monsterList *headMonster;
    bulletList *headBullet;
};


//funzioni per gestire le liste
/*
nuovoSparo
nuovoMostro
eliminaSparo
eliminaMostro
*/

#endif