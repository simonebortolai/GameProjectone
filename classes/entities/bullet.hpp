#ifndef BULLET_HPP_INCLUDED
#define BULLET_HPP_INCLUDED

#include "entity.hpp"
#include "../misc.hpp"

class Bullet : public Entity {
    private:
        int speed;
        int damage;
        
    public:
        //costruttori
        Bullet(point position, char sprite, int speed);

        //set functions
        void setSpeed(int s);

        //get function
        int getSpeed();
};


#endif