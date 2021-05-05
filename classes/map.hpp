#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <ncurses.h>
#include "misc.hpp"
#include "miscFunc.hpp"
#include "room.hpp"
#include "printer.hpp"


struct roomList {
    Room *value;
    roomList *next;
    roomList *prev;
};

typedef roomList *pRoomList;


class Map {
    protected:
        int counter;            //contatore di stanza
        point boxDim;           //dimensione stanze     
        pRoomList currentRoom;
        pRoomList firstRoom;     
        allEntityList * allEntity;

        void writePlayer(LivingEntity * player);
        void addRoomToTail();
        void eraseAllEntities();
        void writeAllEntities();
        void checkPlayerPosition(roomPoint pPos);

    public:
        Map(allEntityList * al, point dim);

        void moveAllEntities();
        roomPoint virtualToReal(point p);
        point realToVirtual(roomPoint rPoint);
        bool isPointAviable(point p);

        //set function
        void writeCharInRoom(char ch, roomPoint rPoint);

        //get function
        char ** getVisualizedWindow();

};

#endif