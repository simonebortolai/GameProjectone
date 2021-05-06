#include <ncurses.h>
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"
#include "./classes/map.hpp"
#include "./classes/keymanager.hpp"
#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time (per srand e rand) */

int main() {
    
    
    //init
    srand(time(NULL)); 
    bool exit = false;


    //Structs
    point dimension {79, 23};    //dimensione finestra dove si gioca
    allEntityList listAllEntity {new LivingEntity({1, 10}, '@', 100, 10), NULL, NULL};


    //Objects
    point roomSize {dimension.x-1, dimension.y-1};
    Map map(&listAllEntity, roomSize);
    KeyManager km(&listAllEntity, &map);
    //iteratore?


    initScreen();   //creo la window con ncurses


    //game loop
    while(!exit) {

        exit = km.selectAction();
        km.checkAllMovement();

        /*
        //da implementare
        km.checkInteraction()           -> controlla le iterazioni tra sparo-nemici e nemici-giocatore
        */
        
        
        map.moveAllEntities();
        printEverything(map.getVisualizedWindow(), roomSize, dimension);
        loop();
    }
    
    endwin();

}