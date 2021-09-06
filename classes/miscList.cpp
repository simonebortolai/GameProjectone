#include "miscList.hpp"

//aggiunge un nuovo proiettile alla lista
pBullet newBullet(pBullet list, Bullet * b){
    pBullet tmp=new bulletList;
    tmp->value=b;
    tmp->next=list;
    return tmp;
}

//aggiunge un nuovo mostro alla lista 
pMonster newMonster(pMonster list, LivingEntity * b){
    pMonster tmp=new monsterList;
    tmp->value=b;
    tmp->next=list;
    return tmp;
}

//aggiunge un nuovo bunus alla lisat
pBonus newBonus(pBonus list, Element * b) {
    pBonus tmp = new bonusList;
    tmp->value = b;
    tmp->next = list;
    return tmp;
}


//rimuove il proiettile desiderato dalla lista
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

//rimuove il mostro desiderato dalla lista
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

//rimuove il bonus desiderato dalla lista
pBonus removeBonus(pBonus list, Element *b){
    pBonus prev=list, tmp_head = list, del=NULL;
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