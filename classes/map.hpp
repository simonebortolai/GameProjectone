#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <ncurses.h>
#include <iostream>
#include "misc.hpp"
#include "miscFunc.hpp"
#include "room.hpp"
#include "printer.hpp"
#include "simpleMap.hpp"



class Map : public SimpleMap {
    protected:
        allEntityList * allEntity;

        void writePlayer();
        void eraseAllEntities();
        void writeAllEntities();
        void checkPlayerPosition(roomPoint pPos);
        void changePos();
        void addRoomToTail();

    public:
       
        Map(allEntityList * al, point dim);
        void moveAllEntities();

};

#endif