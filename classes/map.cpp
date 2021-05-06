#include "map.hpp"
using namespace std;


Map::Map(allEntityList * al, point dim) {
    this->allEntity = al;
    this->boxDim = dim;
    counter = -1;

    //creo la prima stanza
    firstRoom = new roomList;
    firstRoom->value = new Room(boxDim, ++counter); //serve che sia ++counter, non cambiare
    firstRoom->next = NULL;
    firstRoom->prev = NULL;
    currentRoom = firstRoom;
}


void Map::addRoomToTail() {
    pRoomList tmp = firstRoom;

    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new roomList;
    tmp->next->value = new Room(boxDim, ++counter); //serve che sia ++counter, non cambiare
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
}


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


void Map::moveAllEntities() {
    eraseAllEntities(); //cancella le entità
    writeAllEntities(); //le scrive dove si devono muovere e setta la nuova posizione
    changePos();
}


void Map::writePlayer() {
    LivingEntity * player = this->allEntity->player;

    //prendo in che stanza è il giocatore
    roomPoint playerDesPos = virtualToReal((*player).getDesiredPosition());
    

    checkPlayerPosition(playerDesPos); //controlli sulla posizione del player

    //setto
    writeCharInRoom('@', playerDesPos);
}


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
}


roomPoint Map::virtualToReal(point p) {
    int nRoom = p.x/boxDim.x;
    int x = p.x%boxDim.x;
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


//controlla nella stanza giusta se il punto è uno spazio
bool Map::isPointAviable(point p) {
    int room = virtualToReal(p).nRoom;                          //trovo la stanza
    point pTemp = {virtualToReal(p).x, virtualToReal(p).y};     //prendo il punto
    //cout << "x = " << pTemp.x <<endl << "y = " << pTemp.y << endl;
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i < room; i++)
        temp = temp->next;

    return temp->value->isEmpty(pTemp);
    //return true;
}


void Map::writeCharInRoom(char ch, roomPoint p) {
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i < p.nRoom; i++)
        temp = temp->next;

    temp->value->setPixel({p.x,p.y}, ch);
}


/*telecamera fissa -> ritorna la current room*/
char ** Map::getVisualizedWindow() {
    return (*currentRoom->value).getContent();
}