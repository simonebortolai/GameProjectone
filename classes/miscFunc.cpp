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

pBonus newBonus(pBonus list, Element * b) {
    pBonus tmp = new bonusList;
    tmp->value = b;
    tmp->next = list;
    return tmp;
}


/* 
    nota bene, qua per controllare quale oggetto eliminare viene controllato
    che l'indirizzo di b sia uguale all'indirizzo degli elementi dentro list
    non so quanto sia giusto, forse dovremmo dare agli oggetti un ID personale e
    controllare quello 
*/
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