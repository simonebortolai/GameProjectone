#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

using namespace std;

#include <ncurses.h>
#include <iostream>
#include "../misc.hpp"

class Element {
    protected:
        point position;
        char sprite;

    public:
        //costructors
        Element(point position, char sprite);

        //get function
        char getSprite();
        point getPosition();

};

#endif