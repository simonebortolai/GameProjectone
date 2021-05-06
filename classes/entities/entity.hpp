#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <ncurses.h>
#include "../misc.hpp"

class Entity {
    protected:
        int idUnico; // DA IMPLEMENTARE!!
        struct point position;
        struct point desiredPos;
        char sprite;

    public:
        //costructors
        Entity(point position, char sprite);

        //set function
        void setPosition(point position);
        void setDesiredPosition(point where);
        void setDesiredPosition(int keyPressed);

        //get function
        char getSprite();
        point getPosition();
        point getDesiredPosition();

        const char * toString();

};

#endif