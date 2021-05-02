#include "map.hpp"


Map::Map(point dimension) {
    this->boxDim = dimension;
}


void Map::writeAllEntities() {
    //write player
    writeCharInRoom((*allEntity->player).getSprite(), virtualToReal((*allEntity->player).getPosition()));

    //write monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom((*ml->value).getSprite(), virtualToReal((*ml->value).getPosition()));
        ml = ml->next;
    }

    //write bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom((*bl->value).getSprite(), virtualToReal((*bl->value).getPosition()));
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