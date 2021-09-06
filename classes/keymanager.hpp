#ifndef KEYMANAGER_HPP_INCLUDED
#define KEYMANAGER_HPP_INCLUDED

#include <ncurses.h>
#include "miscList.hpp"
#include "map.hpp"

class KeyManager {
    private:
        allEntityList * allEntities;
        Map * map;
        point dimension;

        bool entityCheck(Entity * ml, bool isBullet);
        bool bonusCheck(Element * bonus, LivingEntity * player);
        void moveBullets();
        void moveMonster();
        bool interactionBulletMonster(LivingEntity * monster, Bullet * bullet);
        void interactionMonsterPlayer(LivingEntity * player, LivingEntity * monster);
        void useBonus(Element * bonus);

    public:
        KeyManager(allEntityList * allEnt, Map * map, point dimension);

        bool selectAction();
        void setDesiredPositionOfAllEntities();
        void checkAllMovement();
        void checkInteraction();
};

#endif