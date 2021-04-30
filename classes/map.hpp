#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "misc.hpp"
#include "miscFunc.hpp"
#include "room.hpp"


struct roomList {
    Room *value;
    roomList *next;
    roomList *prev;
};

typedef roomList *pRoomList;


class Map {
    protected:
        point boxDim;
        pRoomList currentRoom;
        pRoomList firstRoom;
        allEntityList * allEntity;

        void addTailRoom();

    public:
        Map(point dimension);
        
        void writeCharInRoom(char ch, point point);
        void writeStringInRoom(char* ch, point point);
        roomPoint virtualToReal(point point);
        point realToVirtual(roomPoint point);
        bool isPointAviable(point point);
};

#endif