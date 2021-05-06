#ifndef KEYMANAGER_HPP_INCLUDED
#define KEYMANAGER_HPP_INCLUDED

#include <iostream>
#include <ncurses.h>
#include "miscFunc.hpp"
#include "map.hpp"

class KeyManager{
    private:
        allEntityList * allEntities;
        Map * map;

    public:
        KeyManager(allEntityList * allEnt, Map * map);

        bool selectAction();
        void checkAllMovement();

        //funzioni da fare
        //checkMovement()
        //moveAll()
        //interaction()
};

#endif