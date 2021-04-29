#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "misc.hpp"

class Entity{
    protected:
        point position;
        char sprite;
    public:
        Entity(char sprite);
        Entity(point position, char sprite);
        void setPosition(point position);
        point getPosition();
        point getDesiredPosition();

};

#endif