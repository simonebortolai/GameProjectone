#include "map.hpp"


Map::Map(allEntityList * al, point dimension) {
    this->allEntity = al;
    this->boxDim = dimension;
    currentRoom = NULL;
    firstRoom = NULL;
    addRoomToTail();
}


void Map::addRoomToTail() {
    pRoomList tmp = firstRoom;

    //creo la nuova stanza
    pRoomList add = new roomList;
    add->value = new Room();
    add->next = NULL;

    if(firstRoom != NULL) {
        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = add;
        tmp->next->prev  = tmp;
    } else {
        firstRoom = add;
        firstRoom->prev = NULL;
    }
}


void Map::moveAllEntities() {
    // cancella le entità
    eraseAllEntities();
    // le scrive dove si devono muovere e setta la nuova posizione
    writeAllEntities();
}


// dopo aver disegnato nelle stanze la posizione dell'entità,
// posso impostare quel punto come vera posizione, inoltre
// se il giocatore va oltre un certo punto crea la nuova stanza
void Map::writeAllEntities() {
    //write player
    roomPoint playerPos = virtualToReal((*allEntity->player).getDesiredPosition());
    writeCharInRoom((*allEntity->player).getSprite(), playerPos);
    (*allEntity->player).setPosition((*allEntity->player).getDesiredPosition());

    //aggiungo una stanza se il giocatore va oltre un certo punto
    if(playerPos.x > (boxDim.x/4)-1)
        addRoomToTail();

    //write monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom((*ml->value).getSprite(), virtualToReal((*ml->value).getDesiredPosition()));
        (*ml->value).setPosition((*ml->value).getDesiredPosition());
        ml = ml->next;
    }

    //write bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom((*bl->value).getSprite(), virtualToReal((*bl->value).getDesiredPosition()));
        (*bl->value).setPosition((*bl->value).getDesiredPosition());
        bl = bl->next;
    }
}


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
}


roomPoint Map::virtualToReal(point p) {
    int nRoom = p.x%boxDim.x;
    int x = p.x-(p.x%boxDim.x);
    int y = p.y;
    roomPoint temp {nRoom, x, y};
    return temp;
}


point Map::realToVirtual(roomPoint rPoint) {
    int x = rPoint.nRoom*rPoint.x + rPoint.x;
    int y = rPoint.y;
    point temp {x, y};
    return temp;
}


bool Map::isPointAviable(point p) {
    int room = virtualToReal(p).nRoom;                          //trovo la stanza
    point pTemp = {virtualToReal(p).x, virtualToReal(p).y};     //prendo il punto
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i <= room; i++)
        temp = temp->next;

    return temp->value->isEmpty(pTemp);
}


void Map::writeCharInRoom(char ch, roomPoint p) {

}


void Map::writeStringInRoom(char * ch, roomPoint p) {

}


char ** Map::getVisualizedWindow() {
    //super mega iper funzione di fabio del progetto di prima
    return NULL;
}


pRoomList Map::getCurrentRoom() {
    return currentRoom;
}


pRoomList Map::getFirstRoom() {
    return firstRoom;
}