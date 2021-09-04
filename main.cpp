#include <ncurses.h>
#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time (per srand e rand) */
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"
#include "./classes/map.hpp"
#include "./classes/keymanager.hpp"


int main() {
    
    //init
    srand(time(NULL));
    bool exit = false;


    //Structs
    point dimension {79, 23};    //dimensione finestra dove si gioca
    point roomSize {dimension.x-1, dimension.y-1};
    allEntityList listAllEntity {new LivingEntity({1, 10}, '@', 100, 10, 0), NULL, NULL, NULL};
    
    
    //Objects
    Map map(&listAllEntity, roomSize);
    KeyManager km(&listAllEntity, &map, dimension);


    initScreen();   //creo la window con ncurses


    /* game loop: esco se viene premuto F4 o il giocatore muore */
    while(!exit) {
        exit = km.selectAction();                                           
        //imposto dove si vuole muovere il player
        km.moveEntities();                                                  
        //imposto dove si vogliono muovere i mostri e gli spari
        km.checkInteraction();                                              
        //controllo le iterazioni tra le entità
        km.checkAllMovement();                                              
        //controllo i movimenti di tutte le entità
        map.moveAllEntities();                                              
        //scrivo nella mappa le entità
        printEverything(map.getVisualizedWindow(), roomSize, dimension, listAllEntity.player);    //scrivo a schermo la mappa disualizzata dal player
        loop();                                                             //eseguo opearazioni ricorrenti ogni ciclo
    }
    
    endwin();
    
}