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
    struct point playerStartingPosition {2, 22};

    allEntityList listAllEntity {new LivingEntity(playerStartingPosition, '@', 100, 10)};

    initScreen();


    while(exit != -1) {
        getch();
        //checkAllMovement()
        //moveAll()
        //checkInteraction()
        //gameMap.updateEntity()
        printEverything(listAllEntity.player, dimension);
        //loop()
        timeout(50);
    }
    
    endwin();

}