#include <ncurses.h>
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"


int main() {
    
    int exit = 0;

    /*
    inizializzo le entità
    inizializzo la mappa (gli passo le entità)
    inizializzo l'iteratore/keyManager
    */

    //Objects
    struct point dimension {79, 23};

    allEntityList * listAllEntity;

    initScreen();
    listAllEntity = initEntity(dimension);


    while(exit != -1) {
        
        //checkAllMovement()
        //moveAll()
        //checkInteraction()
        //gameMap.updateEntity()
        printEverything(dimension);
        //loop()
        timeout(50);   
    }
    
    endwin();

}