#ifndef LIVINGENTITY_HPP_INCLUDED
#define LIVINGENTITY_HPP_INCLUDED

#include "entity.hpp"

class LivingEntity: public Entity{
    private:
        int life;
        int strength;
    public:
        void addLife(int n);
        void subLife(int n);
        int getLife();
};



#endif
