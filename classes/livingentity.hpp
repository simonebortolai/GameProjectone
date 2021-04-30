#ifndef LIVINGENTITY_HPP_INCLUDED
#define LIVINGENTITY_HPP_INCLUDED

#include "entity.hpp"
#include "misc.hpp"


class LivingEntity : public Entity {
    private:
        int life;
        int strength;
    public:
        LivingEntity(point dim, char sprite, int life, int strength);
        void addLife(int n);
        void subLife(int n);
        void setLife(int n);
        void setStrength(int n);
        int getLife();
        int getStrength();
};


#endif