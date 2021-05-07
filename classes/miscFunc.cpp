#include "miscFunc.hpp"

pBullet newBullet(pBullet list, Bullet * b){
    pBullet tmp=new bulletList;
    tmp->value=b;
    tmp->next=list;
    return tmp;
}

pMonster newMonster(pMonster list, LivingEntity * b){
    pMonster tmp=new monsterList;

    tmp->value=b;
    tmp->next=list;

    return tmp;
}

pBullet removeBullet(pBullet list, Bullet *b){
    return NULL;
}

pMonster removeMonster(pMonster list, LivingEntity *b){
    return NULL;
}