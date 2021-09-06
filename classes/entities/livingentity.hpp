#ifndef LIVINGENTITY_HPP_INCLUDED
#define LIVINGENTITY_HPP_INCLUDED

#include "entity.hpp"
#include "../misc.hpp"

class LivingEntity : public Entity {
    private:
        int life;
        int strength;
        int points;

    public:
        LivingEntity(point dim, char sprite, int life, int strength, int points);

        //set function
        void addLife(int n);
        void subLife(int n);
        void setLife(int n);
        void setStrength(int n);
        void setPoints(int n);

        //get function
        int getLife();
        int getStrength();
        int getPoints();

};

#endif