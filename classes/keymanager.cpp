#include <ncurses.h>
#include "keymanager.hpp"
#include "misc.hpp"

KeyManager::KeyManager(allEntity *allEnt) {
    this->player = (*allEnt).player;
}



int KeyManager::selectAction() {
    int keyPressed = getch();
    if (keyPressed == KEY_UP) {

    } else if (keyPressed == KEY_DOWN) {

    } else if (keyPressed == KEY_LEFT) {

    } else if (keyPressed == KEY_RIGHT) {

    } 
    else if (keyPressed == 'e') {

    } 
    else if (keyPressed == KEY_F(4)) {

    } 
    else if (keyPressed == KEY_UP) {

    }
    
}