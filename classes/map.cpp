#include "map.hpp"


Map::Map(allEntityList * al, point dim) : SimpleMap(dim) {
    this->allEntity = al;
}


void Map::addRoomToTail() {
    SimpleMap::addRoomToTail();
    
    // get last room
    pRoomList tmp = firstRoom;
    int counter = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        counter++;
    }

    point offset = realToVirtual({counter, 0, 0});
    this->allEntity->headMonster = (*(tmp->value)).generateEnemies(this->allEntity->headMonster, offset);

    //genera il bonus (una volta su 3)
    int chance = random(1, 4);
    if (chance == 1) {
        this->allEntity->headBonus = (*(tmp->value)).generateBonus(this->allEntity->headBonus, offset);
    }
}


// crea una nuova stanza se il giocatore vuole cambiare stanza e non esiste
void Map::checkPlayerPosition(roomPoint playerDesPos) {
    if(playerDesPos.nRoom == counter && playerDesPos.x >= boxDim.x-1)
        addRoomToTail();

    if(playerDesPos.nRoom != (*currentRoom->value).getLevel()) {
        pRoomList tmp = firstRoom;
        for(int i = 0; i < playerDesPos.nRoom; i++)
            tmp = tmp->next;
        currentRoom = tmp;
    }
}


void Map::writeOnMapAllEntities() {
    eraseAllEntities(); // cancella le entità
    writeAllEntities(); // le scrive dove si devono muovere e setta la nuova posizione
    changePos();
}


void Map::writePlayer() {
    LivingEntity * player = this->allEntity->player;

    //prendo in che stanza è il giocatore
    roomPoint playerDesPos = virtualToReal((*player).getDesiredPosition());
    
    checkPlayerPosition(playerDesPos); //controlli sulla posizione del player

    //setto
    writeCharInRoom(player->getSprite(), playerDesPos);
}


// cambia la posizione delle entità a quella desiderata
void Map::changePos() {
    LivingEntity * player = this->allEntity->player;
    (*player).setPosition((*player).getDesiredPosition());

    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        (*ml->value).setPosition((*ml->value).getDesiredPosition());
        ml = ml->next;
    }

    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        (*bl->value).setPosition((*bl->value).getDesiredPosition());
        bl = bl->next;
    }
}


// scrive nelle stanze tutte le entità
void Map::writeAllEntities() {
    //write player
    writePlayer();

    //write monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom((*ml->value).getSprite(), virtualToReal((*ml->value).getDesiredPosition()));
        ml = ml->next;
    }

    //write bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom((*bl->value).getSprite(), virtualToReal((*bl->value).getDesiredPosition()));
        bl = bl->next;
    }

    //write bonus
    pBonus bonTmp = allEntity->headBonus;
    while(bonTmp != NULL) {
        writeCharInRoom((*bonTmp->value).getSprite(), virtualToReal((*bonTmp->value).getPosition()));
        bonTmp = bonTmp->next;
    } 
}


//sostituisce al posto delle entità uno spazio
void Map::eraseAllEntities() {
    //erase player
    writeCharInRoom(' ', virtualToReal((*allEntity->player).getPosition()));

    //erase monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom(' ', virtualToReal((*ml->value).getPosition()));
        ml = ml->next;
    }

    //erase bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom(' ', virtualToReal((*bl->value).getPosition()));
        bl = bl->next;
    }

    //erase bonuses
    pBonus bonTmp = allEntity->headBonus;
    while(bonTmp != NULL) {
        writeCharInRoom(' ', virtualToReal((*bonTmp->value).getPosition()));
        bonTmp = bonTmp->next;
    } 
}