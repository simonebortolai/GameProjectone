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

    struct allEntityList listAllEntity {new LivingEntity({2, 22}, '@', 100, 10), NULL, NULL};

    initScreen();


    while(exit != -1) {

        getch();
        //checkAllMovement()
        //moveAll()
        //checkInteraction()
        //gameMap.updateEntity(listAllEntity) -> bello peso da fare forse, si dovrebbe cancellare gli sprite e riscriverli nei punti aggiornati
        printEverything(listAllEntity.player, dimension); //passaggio di player temporanero, dopo si passa solo la stanza
        //loop()
        
    }
    
    endwin();

}