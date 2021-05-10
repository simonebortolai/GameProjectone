#include "miscFunc.hpp"

pBullet newBullet(pBullet list, Bullet *b ){
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
    pBullet prev=list, tmp_head = list, del=NULL;
    while(tmp_head != NULL){
        if(tmp_head->value == b){
            if(tmp_head == list){
                prev = list->next;
                tmp_head = list->next;
                list = list->next;
            }
            else{
                del = tmp_head;
                prev->next = tmp_head->next;
                delete del;
            }
        }
        tmp_head = tmp_head->next;
    }
    return list;
}

pMonster removeMonster(pMonster list, LivingEntity *b){
    pMonster prev=list, tmp_head = list, del=NULL;
    while(tmp_head != NULL){
        if(tmp_head->value == b){
            if(tmp_head == list){
                prev = list->next;
                tmp_head = list->next;
                list = list->next;
            }
            else{
                del = tmp_head;
                prev->next = tmp_head->next;
                delete del;
            }
        }
        tmp_head = tmp_head->next;
    }
    return list;
}