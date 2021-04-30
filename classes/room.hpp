#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp";

//simo/ceci, create 3 prototipi di stanze grandezza {23, 79}
/*
char ** room1 = ["    ",
                 "    "];
char ** room2 = ["    ",
                 "    "];
char ** room3 = ["    ",
                 "    "];
*/

class Room {
    protected:
        char** content;
        //lista nemici?

    public:
        void generateRoom();
        char** getContent();
        bool isEmpty(point p);

};

#endif