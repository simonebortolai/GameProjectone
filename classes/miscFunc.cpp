#include "miscFunc.hpp"

pBullet newBullet(pBullet list, Bullet *b){
    pBullet tmp=new bulletList;

    tmp->value=b;
    tmp->next=list;
    list->next=tmp;

    return list;

}

pMonster newMonster(pMonster list, LivingEntity *b){
    pMonster tmp=new monsterList;

    tmp->value=b;
    tmp->next=list;
    list->next=tmp;

    return list;


}

pBullet removeBullet(pBullet list, Bullet *b){

}

pMonster removeMonster(pMonster list, LivingEntity *b){

}