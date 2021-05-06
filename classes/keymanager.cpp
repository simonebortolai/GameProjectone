#include "keymanager.hpp"


KeyManager::KeyManager(allEntityList * allEnt, Map * map, point dimension) {
    allEntities = allEnt;
    this->map = map;
    this->dimension = dimension;
}


bool KeyManager::selectAction() {
    int keyPressed = getch();
    LivingEntity * player = this->allEntities->player;
    //bulletList * bl = allEntities->headBullet;

    //se il giocatore muore finisce il gioco
    if(player->getLife() <= 0)
        return true;
    
    if (keyPressed == KEY_UP || keyPressed == KEY_DOWN || keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT) {
        (*player).setDesiredPosition({keyPressed});
    } else if ((char)keyPressed == 'e') {
        //perché non funzia?
        //bl = newBullet(bl, new Bullet((*player).getPosition(), '-', 2));
    }
    else if (keyPressed == KEY_F(4))
        return true;
    //else
        //(*player).setDesiredPosition(KEY_DOWN); // gravity?


    return false;
}


void KeyManager::checkAllMovement() {
    //player check
    LivingEntity * player = allEntities->player;
    point p1 = (*player).getDesiredPosition();
    if(p1.y < 0 || p1.y >= this->dimension.y-1 || p1.x < 0)
        (*player).setDesiredPosition((*player).getPosition()); // torna a dove era prima
    else if(!(*map).isPointAviable(p1))
        (*player).setDesiredPosition((*player).getPosition()); // torna a dove era prima
    

    (*player).setDesiredPosition(KEY_DOWN);
    point p2 = (*player).getDesiredPosition();
    if(p2.y < 0 || p2.y >= this->dimension.y-1 || p2.x < 0) {
        if(p1.y < 0 || p1.y >= this->dimension.y-1 || p1.x < 0)
            (*player).setDesiredPosition((*player).getPosition());
        else
            (*player).setDesiredPosition(p1);
    } else if ((*map).isPointAviable(p2))
        (*player).setDesiredPosition(p2);
    else
        (*player).setDesiredPosition(p1);

    
}