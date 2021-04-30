#include "map.hpp"


Map::Map(point dimension) {
    this->boxDim = dimension;
}


void Map::writeCharInRoom(char ch, point point) {

}


void Map::writeStringInRoom(char * ch, point point) {

}


roomPoint Map::virtualToReal(point point) {
    int nRoom = point.x%point.x;
    int x = point.x-point.x%point.x;
    int y = point.y;
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
    int room = virtualToReal(p).nRoom;                          //trovo la stanza a cui fa riferimento
    point pTemp = {virtualToReal(p).x, virtualToReal(p).y};     //prendo il punto a cui fa riferimento della stanza
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i <= room; i++)
        temp = temp->next;

    return temp->value->isEmpty(pTemp);
}