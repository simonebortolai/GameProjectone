#include <ncurses.h>
#include "keymanager.hpp"
#include "misc.hpp"

KeyManager::KeyManager(allEntityList * allEnt, Map * map) {
    allEntities = allEnt;
    this->map = map;
}



int KeyManager::selectAction() {
    int keyPressed = getch();
    LivingEntity * player = this->allEntities->player;

    if(player->getLife() <= 0) {
        return true;
    }
    
    //muovo il giocatore
    if (keyPressed == KEY_UP || keyPressed == KEY_DOWN || keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT)
    {
        player->setDesiredPosition(keyPressed);
        return false;
    } 
    else if (keyPressed == 'e')
    {
        // nuovo sparo
        return false;
    } 
    else if (keyPressed == KEY_F(4)) //esco
    {
        return true;
    }
    else {
        return false;
    }
    
}