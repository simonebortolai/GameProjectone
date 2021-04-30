#ifndef BULLET_HPP_INCLUDED
#define BULLET_HPP_INCLUDED

#include "entity.hpp"
#include "../misc.hpp"

class Bullet : public Entity {
    private:
        int speed;
    public:
        Bullet(point position, char sprite, int speed);
        int getSpeed();
        void setSpeed(int s);
};


#endif