#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "../misc.hpp"
#include <cstring>

class Entity {
    protected:
        struct point position;
        char sprite;
    public:
        Entity(char sprite);
        Entity(point position, char sprite);
        void setPosition(point position);
        char getSprite();
        point getPosition();
        point getDesiredPosition();

        const char * toString();

};

#endif