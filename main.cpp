#include <iostream>
#include <ncurses.h>
#include "./classes/misc.hpp"
#include "./classes/miscFunc.hpp"
#include "./classes/printer.hpp"
#include "./classes/map.hpp"
#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time (per srand e rand) */
using namespace std;

int main() {
    
    //init
    srand(time(NULL)); 
    bool exit = false;


    //Structs
    point dimension {79, 23};    //dimensione finestra dove si gioca
    allEntityList listAllEntity {new LivingEntity({1, 10}, '@', 100, 10), NULL, NULL};

    
    /*
    //Objects
    KeyMenager km(&listAllEntity, &map);
    iteratore  -> da pensare
    */

    point roomSize {dimension.x-1, dimension.y-1};
    Map map(&listAllEntity, roomSize);

    //DEBUG
    LivingEntity * player = listAllEntity.player;
    

    initScreen();   //creo la window con ncurses

    int lr = 0;
    //game loop
    while(!exit) {
        /*
        da implementare
        exit = kayManager.selection()   -> prende il tasto premuto, cambia la desired position del player, crea spari
        km.checkAllMovement()           -> controlla se le entità si pussono muovere nelle desired position
        km.moveAll()                    -> aggiorna le posizioni
        km.checkInteraction()           -> controlla le iterazioni tra sparo-nemici e nemici-giocatore
        */
        
        // debug
        point tmp = (*player).getPosition();

        if (tmp.x == 120) lr = 1;
        if(lr == 1) tmp.x--;
        else tmp.x++;

        (*player).setDesiredPosition(tmp);



        map.moveAllEntities();
        printEverything(map.getVisualizedWindow(), roomSize, dimension);
        loop();
    }
    
    endwin();

}