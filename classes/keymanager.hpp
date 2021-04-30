#ifndef KEYMANAGER_HPP_INCLUDED
#define KEYMANAGER_HPP_INCLUDED

#include "misc.hpp"
#include "livingentity.hpp"

class KeyManager{
    private:
        LivingEntity *player;

    public:
        KeyManager(allEntity *allEnt);
        int selectAction();
        
};

#endif