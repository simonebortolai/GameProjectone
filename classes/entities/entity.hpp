#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <ncurses.h>
#include "../misc.hpp"
#include "element.hpp"

class Entity : public Element {
    protected:
        point desiredPos;

        //jump
        int direction;
        int jumpTicks;
        int isJumping;

    public:
        //costructors
        Entity(point position, char sprite);
        Entity(point position, char sprite, int direction);

        void jump();
        void animation(bool isMonster);

        //set function
        void setPosition(point position);
        void setDesiredPosition(point where);
        void setDesiredPosition(int keyPressed);

        //get function
        point getDesiredPosition();
        int getDirection();
        int getIsJumping();

};

#endif