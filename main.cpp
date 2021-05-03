#include <ncurses.h>
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"
#include "./classes/map.hpp"


int main() {
    
    //Datas
    int exit = 0;


    //Structs
    point dimension {79, 23};    //dimensione finestra
    //setto da qua tutte le proprietà di player, inizializzo a null la lista dei mostri e dei bullets
    allEntityList listAllEntity {new LivingEntity({2, 22}, '@', 100, 10), NULL, NULL};

    
    //Objects
    Map map(&listAllEntity, dimension);
    /*
    KeyMenager km(&listAllEntity, &map);
    iteratore  -> da pensare
    */


    initScreen();

    //game loop
    while(exit != -1) {
        /*
        da implementare
        exit = kayManager.selection()   -> prende il tasto premuto, cambia la desired position del player, crea spari
        km.checkAllMovement()           -> controlla se le entità si pussono muovere nelle desired position
        km.moveAll()                    -> aggiorna le posizioni
        km.checkInteraction()           -> controlla le iterazioni tra sparo-nemici e nemici-giocatore
        */
        map.moveAllEntities();              //cancella la precedente posizione delle entità e le riscrive nelle desired position
        printEverything('@', dimension);    //da sostituire a: printEverything(map.getVisualizedWindow(), dimension);
        loop();
    }
    
    endwin();

}