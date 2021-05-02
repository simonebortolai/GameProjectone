#include <ncurses.h>
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"
#include "./classes/room.hpp"


int main() {
    
    //Datas
    int exit = 0;


    //Structs
    struct point dimension {79, 23};    //dimensione finestra
    //setto da qua tutte le proprietà di player, inizializzo a null la lista dei mostri e dei bullets
    struct allEntityList listAllEntity {new LivingEntity({2, 22}, '@', 100, 10), NULL, NULL};

    /*
    //Objects
    Map map(&listAllEntity)                 //inizializzo la mappa (gli passo le entità)
    KeyMenager km(&listAllEntity, &map)     //inizializzo l'iteratore/keyManager
    */

    //DEBUG
    point roomSize {dimension.x-1, dimension.y-1};
    Room stanza (roomSize, 0);
    point start {1, 1};
    

    initScreen();


    while(exit != -1) {
        /*
        da implementare
        exit = kayManager.selection()   -> prende il tasto premuto, cambia la desired position del player, crea spari
        km.checkAllMovement()           -> controlla se le entità si pussono muovere nelle desired position
        km.moveAll()                    -> aggiorna le posizioni
        km.checkInteraction()           -> controlla le iterazioni tra sparo-nemici e nemici-giocatore
        map.updateEntity()              -> cancellare gli sprite e riscriverli nei punti aggiornati
        printEverything(currentWindow, dimention)
        */

        startDraw();
        printRoom(stanza.getContent(), start, roomSize);
        printEverything(listAllEntity.player, dimension); //temporaneo
        endDraw();
        loop();
    }
    
    endwin();

}