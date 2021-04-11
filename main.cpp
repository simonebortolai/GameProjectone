#include <ncurses.h>
#include "./classes/keymanager.hpp"
#include "./classes/map.hpp"
#include "./classes/misc.hpp"


point dimension {23, 79};




int main() {

    int exit;

    // Objects
    KeyManager km;
    Map gameMap(dimension);

    // esce se viene premuto il tasto F4 o il personaggio muore
    while(exit != -1) {

        exit = km.keyManage();
        
        //checkAllMovement()
        //moveAll()
        //checkInteraction()
        //gameMap.updateEntity()
        //printEverything()
        //loop()
    }
    

}