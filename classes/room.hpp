#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp"


class Room {
    protected:
        point dimension;
        char** content;
        void generateRoom(int level);
        //lista nemici?

    public:
        Room(point dimension, int level);
        char ** getContent();
        bool isEmpty(point p);

};


/*
Sono costretto a dichiarare content pointer of pointer anche se in realtà il size è fissato e conosciuto durante la compilazione, C++ non è abbastanza intelligente 
*/

#endif