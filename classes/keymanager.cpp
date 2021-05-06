#include "keymanager.hpp"


KeyManager::KeyManager(allEntityList * allEnt, Map * map) {
    allEntities = allEnt;
    this->map = map;
}


bool KeyManager::selectAction() {
    int keyPressed = getch();
    LivingEntity * player = this->allEntities->player;

    //se il giocatore muore finisce il gioco
    if(player->getLife() <= 0) return true;
    
    //muovo il giocatore
    if (keyPressed == KEY_UP || keyPressed == KEY_DOWN || keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT) {
        (*player).setDesiredPosition(keyPressed);
    } else if ((char)keyPressed == 'e') {
        // nuovo sparo
    } 
    else if (keyPressed == KEY_F(4))
        return true;
        
    return false;
}


void KeyManager::checkAllMovement() {
    //player check
    LivingEntity * player = allEntities->player;
    if(!(*map).isPointAviable((*player).getDesiredPosition()))
        (*player).setDesiredPosition((*player).getPosition());
}