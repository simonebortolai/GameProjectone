#ifndef KEYMANAGER_HPP_INCLUDED
#define KEYMANAGER_HPP_INCLUDED

#include "miscFunc.hpp"
#include "map.hpp"

class KeyManager{
    private:
        allEntityList * allEntities;
        Map * map;

    public:
        KeyManager(allEntityList * allEnt, Map * map);
        int selectAction();

        //funzioni da fare
        //checkMovement()
        //moveAll()
        //interaction()
};

#endif