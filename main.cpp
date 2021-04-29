#include <ncurses.h>
//#include "./classes/keymanager.hpp"
//#include "./classes/map.hpp"
#include "./classes/misc.hpp"
#include "./classes/printer.hpp"

//da spostare
void initScreen() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

point dimension {79, 23};


int main() {

    int exit = 0;

    /* 
    //Objects
    
    allEntity *listAllEntity;

    //Map gameMap(dimension);
    //KeyManager km();
    */

    // esce se viene premuto il tasto F4 o il personaggio muore

    initScreen();
    //initEntity();


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