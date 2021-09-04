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

        //riconosco il tasto premuto e imposto la desiredPosition del player
        exit = km.selectAction();

        //imposto le desiredPosition di mostri e spari
        km.setDesiredPositionOfAllEntities();

        //controllo le iterazioni tra le entità
        km.checkInteraction();

        //controllo le desiredPosition di tutte le entità e le gestisco
        km.checkAllMovement();

        //scrivo nella mappa tutte entità
        map.writeOnMapAllEntities();

        //stampo a schermo la mappa visualizzata dal player e UI di gioco
        printEverything(map.getVisualizedWindow(), roomSize, dimension, listAllEntity.player);

         //eseguo opearazioni ricorrenti ogni ciclo
        loop();
    }
    
    endwin();
    
}