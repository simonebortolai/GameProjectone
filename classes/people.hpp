#ifndef PEOPLE_HPP_INCLUDED
#define PEOPLE_HPP_INCLUDED

#include "entity.hpp"

class LivingEntity: public Entity{
    private:
        int life;
        int strenght;
    public:
        void addLife(int n);
        void subLife(int n);
        int getLife();
};



#endif
