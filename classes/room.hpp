#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp"
#include "space2d.hpp"


class Room : public Space2d {
    protected:
        void generateRoom(int level);
        void generatePlatform();
        //lista nemici?

    public:
        Room(point size, int level);
        bool isEmpty(point p);

};




#endif