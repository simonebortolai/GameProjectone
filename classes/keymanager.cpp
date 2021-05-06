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
    
    if (keyPressed == KEY_UP || keyPressed == KEY_DOWN || keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT)
        (*player).setDesiredPosition(keyPressed);
    else if ((char)keyPressed == 'e') {
        //perché non funzia?
        //bl = newBullet(bl, new Bullet((*player).getPosition(), '-', 2));
    }
    else if (keyPressed == KEY_F(4))
        return true;


    return false;
}


void KeyManager::entityCheck(Entity * ent, bool isBullet) {
    point p2, p1 = (*ent).getDesiredPosition();
    if(p1.y < 0 || p1.y >= this->dimension.y-1 || p1.x < 0)     // se va fuori il campo
        (*ent).setDesiredPosition((*ent).getPosition());            // torna a dove era prima
    else if(!(*map).isPointAviable(p1))                         // se va in un punto occupato
        (*ent).setDesiredPosition((*ent).getPosition());            // torna a dove era prima
    
    //se non è un proiettile applica gravità
    if(!isBullet) {
        (*ent).setDesiredPosition(KEY_DOWN);
        p2 = (*ent).getDesiredPosition();
        if(p2.y < 0 || p2.y >= this->dimension.y-1 || p2.x < 0) {
            if(p1.y < 0 || p1.y >= this->dimension.y-1 || p1.x < 0)
                (*ent).setDesiredPosition((*ent).getPosition());
            else
                (*ent).setDesiredPosition(p1);
        } else if ((*map).isPointAviable(p2))
            (*ent).setDesiredPosition(p2);
        else
            (*ent).setDesiredPosition(p1);
    }
}


void KeyManager::moveBullets() {
    bulletList * bl = allEntities->headBullet;
    point tmp;
    while (bl != NULL) {
        tmp = (*bl->value).getPosition();
        tmp.x += (*bl->value).getSpeed();
        (*bl->value).setDesiredPosition(tmp);
        bl = bl->next;
    }
}


void KeyManager::moveMonster() {}


void KeyManager::moveEntities() {
    moveBullets();
    moveMonster();
}


void KeyManager::checkAllMovement() {
    monsterList * ml = allEntities->headMonster;
    bulletList * bl = allEntities->headBullet;

    entityCheck(allEntities->player, false);

    while (ml!= NULL) {
        entityCheck(ml->value, false);
        ml = ml->next;
    }
    
    while (bl!= NULL) {
        entityCheck(bl->value, true);
        bl = bl->next;
    }
}