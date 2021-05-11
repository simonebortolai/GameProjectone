#include "simpleMap.hpp"


SimpleMap::SimpleMap(point dim) {
    this->boxDim = dim;
    counter = -1;

    //creo la prima stanza
    firstRoom = NULL;
    addRoomToTail();    
    currentRoom = firstRoom;
}


void SimpleMap::addRoomToTail() {
    pRoomList newroom = new roomList;
    newroom->value = new Room(boxDim, ++counter); //serve che sia ++counter, non cambiare
    newroom->next = NULL;

    if (firstRoom == NULL) {
        firstRoom = newroom;
        newroom->prev = NULL;
    } else {
        pRoomList tmp = firstRoom;

        while(tmp->next != NULL) 
            tmp = tmp->next;

        tmp->next = newroom;
        newroom->prev = tmp;
    }
}


roomPoint SimpleMap::virtualToReal(point p) {
    int nRoom = p.x/boxDim.x;
    int x = p.x%boxDim.x;
    int y = p.y;
    roomPoint temp {nRoom, x, y};
    return temp;
}


point SimpleMap::realToVirtual(roomPoint rPoint) {
    int x = rPoint.nRoom*boxDim.x + rPoint.x;
    int y = rPoint.y;
    point temp {x, y};
    return temp;
}


//controlla nella stanza giusta se il punto è uno spazio
bool SimpleMap::isPointAviable(point p) {
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


void SimpleMap::writeCharInRoom(char ch, roomPoint p) {
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i < p.nRoom; i++)
        temp = temp->next;

    temp->value->setPixel({p.x,p.y}, ch);
}


/*telecamera fissa -> ritorna la current room*/
char ** SimpleMap::getVisualizedWindow() {
    return (*currentRoom->value).getContent();
}


int SimpleMap::getLevel() {
    return counter;
}