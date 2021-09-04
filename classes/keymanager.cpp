#include "keymanager.hpp"

#define NODIR -1
#define RIGHT 0
#define LEFT 1

KeyManager::KeyManager(allEntityList * allEnt, Map * map, point dimension) {
    allEntities = allEnt;
    this->map = map;
    this->dimension = dimension;
}


bool KeyManager::selectAction() {
    LivingEntity * player = this->allEntities->player;
    int dir = (*player).getDirection(), keyPressed = getch();
    point tmp = (*player).getPosition();

    if(player->getLife() <= 0)              // se il giocatore è morto finisce il gioco
        return true;

    if (keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT)
        (*player).setDesiredPosition(keyPressed);
    else if (keyPressed == KEY_UP){
        tmp.y++;
        if((*map).isPointFloor(tmp))        // se il punto sotto il giocatore è un pavimento può saltare
            (*player).jump();
    } else if ((char)keyPressed == 'e'){    // sparo
        if(dir == LEFT) tmp.x--;
        else            tmp.x++;
        if(tmp.x < 0) {}
        else if((*map).isPointAviable(tmp)) allEntities->headBullet = newBullet(allEntities->headBullet, new Bullet(tmp, '-', 1, 10, dir));
    } else if (keyPressed == KEY_F(4)){
        return true;
    } else if((char)keyPressed == 'f'){
       /*
        tmp.x += 1;
        if((*map).isPointAviable(tmp))
            this->isBonus(tmp);
        tmp.x -= 2;
        if((*map).isPointAviable(tmp))
            this->isBonus(tmp);
            */
    }

    return false;
}


//funzione che controlla la desiredPosition di un entità generica e la gestisce
bool KeyManager::entityCheck(Entity * ent, bool isBullet) {
    int level = (*map).getLevel();
    point p1 = (*ent).getDesiredPosition(), p2;

    if(isBullet) {
        if(p1.x < 0 || p1.x >= (this->dimension.x-1) * (level + 1)) {       //se vuole andare oltre alla mappa creata per ora
            (*ent).setDesiredPosition((*ent).getPosition());                    //lo cancello
            return true;
        }else if(!(*map).isPointAviable(p1)) {
            (*ent).setDesiredPosition((*ent).getPosition());
            return true;
        }
    } else {

        if(p1.y < 0 || p1.y >= this->dimension.y-1 || p1.x < 0)     // se va fuori il campo
            (*ent).setDesiredPosition((*ent).getPosition());            // torna a dove era prima
        else if(!(*map).isPointAviable(p1))                         // se va in un punto occupato
            (*ent).setDesiredPosition((*ent).getPosition());            // torna a dove era prima

        //gravity
        if((*ent).getIsJumping() == 0) {
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
    return false;
}


void KeyManager::moveBullets() {
    bulletList * bl = allEntities->headBullet;

    while (bl != NULL) {
        (*bl->value).goForward();
        bl = bl->next;
    }
}


void KeyManager::moveMonster() {
    monsterList * ml = allEntities->headMonster;
    
    while (ml != NULL) {
        (*ml->value).animation(true);
        ml = ml->next;
    }
}


//toglie vita al mostro se sono vicini
bool KeyManager::interactionBulletMonster(LivingEntity * monster, Bullet * bullet) {
    point bp = (*bullet).getPosition(), mp = (*monster).getPosition();
    if(bp.y == mp.y){
        if(mp.x - bp.x == 1 || mp.x - bp.x == 0 || mp.x - bp.x == -1) {
            (*monster).subLife((*bullet).getDamage());
            return true;
        }
    }
    return false;
}

//toglie vita al player se sono vicini
void KeyManager::interactionMonsterPlayer(LivingEntity * pl, LivingEntity * mn) {
    point playerPoint = (*pl).getPosition(), monsterPoint = (*mn).getPosition();
    if(playerPoint.y == monsterPoint.y){
        if(monsterPoint.x - playerPoint.x <= 2 && monsterPoint.x - playerPoint.x >= -2)
            (*pl).subLife((*mn).getStrength()/10);
    }
}


void KeyManager::setDesiredPositionOfAllEntities() {
    (*allEntities->player).animation(false);
    moveBullets();
    moveMonster();
}


void KeyManager::checkAllMovement() {
    monsterList * ml = allEntities->headMonster;
    bulletList * bl = allEntities->headBullet;
    pBonus bonTemp = allEntities->headBonus;
    bool elim;

    //controllo i bonus (non sono Entity :( )
    while (bonTemp != NULL) {
        elim = bonusCheck(bonTemp->value, allEntities->player);
        if (elim) {
            Element * toBeDel = bonTemp->value;
            bonTemp = bonTemp->next;
            (*map).writeCharInRoom(' ', (*map).virtualToReal((*toBeDel).getPosition()));
            allEntities->headBonus = removeBonus(allEntities->headBonus, toBeDel);
        } else {
            bonTemp = bonTemp->next;
        }
    }


    entityCheck(allEntities->player, false);

    while (ml!= NULL) {
        entityCheck(ml->value, false);
        ml = ml->next;
    }
    
    while (bl!= NULL) {
        elim = entityCheck(bl->value, true);
        if(elim) {
            Bullet * b = bl->value;
            bl = bl->next;
            (*map).writeCharInRoom(' ', (*map).virtualToReal((*b).getPosition()));
            allEntities->headBullet = removeBullet(allEntities->headBullet, b);
        } else {
            bl = bl->next;
        }
    }

    
}


bool KeyManager::bonusCheck(Element * bonus, LivingEntity * player) {
    point desPos = (*player).getDesiredPosition();
    point bonusPos = (*bonus).getPosition();
    if (bonusPos.x == desPos.x && bonusPos.y == desPos.y) {
        useBonus(bonus);
        return true;
    } else {
        return false;
    }
}


void KeyManager::checkInteraction() {
    bool hitted = false, death = false;
    monsterList * ml = allEntities->headMonster;
    bulletList * bl = allEntities->headBullet;

    /* controllo se ogni sparo è vicino a un mostro */
    while (ml!= NULL) {
        death = false;
        hitted = false;
        bl = allEntities->headBullet;

        while (bl != NULL && !hitted) {
            hitted = interactionBulletMonster(ml->value, bl->value);
            if(!hitted)
                bl = bl->next;
        }

        if(hitted) {
            if((*ml->value).getLife() <= 0) {
                death = true;
                allEntities->player->setPoints(allEntities->player->getPoints()+(*ml->value).getPoints());
                LivingEntity * m = ml->value;
                ml = ml->next;
                allEntities->headMonster = removeMonster(allEntities->headMonster, m);
                (*map).writeCharInRoom(' ', (*map).virtualToReal((*m).getPosition()));
            }

            Bullet * b = bl->value;
            (*map).writeCharInRoom(' ', (*map).virtualToReal((*b).getPosition()));
            allEntities->headBullet = removeBullet(allEntities->headBullet, b);
        }

        if(!death)
            ml = ml->next;
    }

    /* controllo se ogni mostro è vicino al giocatore */
    ml = allEntities->headMonster;
    while (ml!= NULL) {
        interactionMonsterPlayer(allEntities->player, ml->value);
        ml = ml->next;
    }
}
/*          
            P = +punti
            I = invicibilità
            V = +vità
            D = +danni
            
            S = +velocità
            
*/
//controlla che bonus c'è a destra del personaggio
void KeyManager::useBonus(Element * bonus){
    if((*bonus).getSprite() == 'P'){
        
    }
    else if((*bonus).getSprite() == 'I'){

    }
    else if((*bonus).getSprite() == 'V'){

    }
    else if((*bonus).getSprite() == 'D'){

    }
    else if((*bonus).getSprite() == 'S'){

    }
}