#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <ncurses.h>
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

        void writeAllEntities();
        roomPoint virtualToReal(point p);
        point realToVirtual(roomPoint rPoint);
        bool isPointAviable(point p);

        //set function
        void writeCharInRoom(char ch, roomPoint rPoint);
        void writeStringInRoom(char* ch, roomPoint rPoint);

        //get function
        pRoomList getCurrentRoom();
        pRoomList getFirstRoom();
        char ** getVisualizedWindow();

};

#endif