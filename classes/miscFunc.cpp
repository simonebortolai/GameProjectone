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
    pBullet prev=list, tmp_head = list, del=NULL;
    bool v = false;
    while(tmp_head != NULL && !v){
        if(tmp_head->value == b){
            if(tmp_head == list){
                del = list;
                list = list->next;
            }
            else{
                del = tmp_head;
                prev->next = tmp_head->next;
            }   
            delete del;
            del = NULL;
            v = true;
        }
        if(!v) {
            prev = tmp_head;
            tmp_head = tmp_head->next;
        }
    }
    return list;
}


pMonster removeMonster(pMonster list, LivingEntity *b){
    pMonster prev=list, tmp_head = list, del=NULL;
    bool v = false;
    while(tmp_head != NULL && !v){
        if(tmp_head->value == b){
            if(tmp_head == list){
                del = list;
                list = list->next;
            }
            else{
                del = tmp_head;
                prev->next = tmp_head->next;
            }   
            delete del;
            del = NULL;
            v = true;
        }
        if(!v) {
            prev = tmp_head;
            tmp_head = tmp_head->next;
        }
    }
    return list;
}