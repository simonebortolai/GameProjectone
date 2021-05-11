#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <ncurses.h>
#include <iostream>
#include "../misc.hpp"

class Entity {
    protected:
        point position;
        point desiredPos;
        char sprite;

        //jump
        int direction;
        bool isJumping;

    public:
        //costructors
        Entity(point position, char sprite);

        void jump();
        void animation();

        //set function
        void setPosition(point position);
        void setDesiredPosition(point where);
        void setDesiredPosition(int keyPressed);

        //get function
        char getSprite();
        point getPosition();
        point getDesiredPosition();

};

#endif