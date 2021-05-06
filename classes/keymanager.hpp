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
        point dimension;

        void entityCheck(Entity * ml, bool isBullet);
        void moveBullets();
        void moveMonster(); //se vogliamo implementare una sorta di movimento verso il giocatore o un movimento ciclico

    public:
        KeyManager(allEntityList * allEnt, Map * map, point dimension);

        bool selectAction();
        void moveEntities();
        void checkAllMovement();

        //funzioni da fare
        //interaction()
};

#endif