#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include "../misc.hpp"

class Element {
    protected:
        point position;
        char sprite;

    public:
        Element(point position, char sprite);

        //get function
        char getSprite();
        point getPosition();

};

#endif