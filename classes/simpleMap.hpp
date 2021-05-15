#ifndef SIMPLEMAP_HPP_INCLUDED
#define SIMPLEMAP_HPP_INCLUDED

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

class SimpleMap {
    protected:           
        int counter;            //contatore di stanza
        point boxDim;           //dimensione stanze     
        pRoomList currentRoom;
        pRoomList firstRoom;

        //void writePlayer();
        void addRoomToTail();


    public:
       
        SimpleMap(point dim);
        roomPoint virtualToReal(point p);
        point realToVirtual(roomPoint rPoint);
        bool isPointAviable(point p);
        bool isPointFloor(point p);

        //set function
        void writeCharInRoom(char ch, roomPoint rPoint);

        //get function
        char ** getVisualizedWindow();
        int getLevel();

};

#endif