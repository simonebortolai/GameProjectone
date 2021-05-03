#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp"


class Room {
    protected:
        char ** content;
        //lista nemici?

    public:
        //generateMonster
        void generateRoom();
        char ** getContent();
        bool isEmpty(point p);

};

#endif