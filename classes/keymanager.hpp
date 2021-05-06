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
        void moveMonster();
        bool iteractionBulletMonster(LivingEntity * monster, Bullet * bullet);

    public:
        KeyManager(allEntityList * allEnt, Map * map, point dimension);

        bool selectAction();
        void moveEntities();
        void checkAllMovement();
        void checkInteraction();

        //funzioni da fare
        //interaction()
};

#endif