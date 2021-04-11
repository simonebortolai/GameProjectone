#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "misc.hpp"
#include "room.hpp"



struct roomList {
    Room *value;
    roomList *next;
    roomList *prev;
};

typedef roomList *pRoomList;


class Map {
    protected:
        pRoomList currentRoom;
        //lista_enemy:
        void addTailRoom();

    public:
        Map(point dimension);
        void writeCharInRoom(char ch, point point);
        void writeStringInRoom(char* ch, point point);
        point virtualToReal(point point);
        point realToVirtual(point point);
        

        
};

#endif