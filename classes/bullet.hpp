#ifndef BULLET_HPP_INCLUDED
#define BULLET_HPP_INCLUDED

#include "entity.hpp"

class Bullet : public Entity{
    private:
        int speed;
    public:
        Bullet(int speed);
        int getSpeed();
        void setSpeed(int s);
};


#endif