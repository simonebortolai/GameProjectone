#ifndef LIVINGENTITY_HPP_INCLUDED
#define LIVINGENTITY_HPP_INCLUDED

#include "entity.hpp"

class LivingEntity: public Entity{
    private:
        int life;
        int strength;
    public:
        LivingEntity(int x, int y, char sprite,int life, int strength);
        void addLife(int n);
        void subLife(int n);
        int getLife();
        void setLife(int n);
        int getStrength();
        void setStrength(int n);
};



#endif
