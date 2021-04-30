#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "../misc.hpp"
#include <cstring>

class Entity {
    protected:
        int idUnico; // DA IMPLEMENTARE!!
        struct point position;
        struct point desiredPos;
        char sprite;

    public:
        //costruttori
        Entity(char sprite);
        Entity(point position, char sprite);

        //set function
        void setPosition(point position);
        void setDesiredPosition(int where);

        //get function
        char getSprite();
        point getPosition();
        point getDesiredPosition();

        const char * toString();

};

#endif