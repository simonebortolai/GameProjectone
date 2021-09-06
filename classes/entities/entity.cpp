#include "entity.hpp"


#define NODIR -1
#define RIGHT 0
#define LEFT 1


Entity::Entity(point p, char s) : Element(p, s) {
    this->desiredPos = p;
    direction = NODIR;
    jumpTicks = 10;
    isJumping = 0;
}


Entity::Entity(point pos, char s, int dir) : Element(pos, s) {
    this->desiredPos = pos;
    jumpTicks = 10;
    isJumping = 0;
    this->direction = dir;
}


void Entity::setPosition(point position){
    this->position = position;
}


void Entity::setDesiredPosition(int keyPressed) {
    if (keyPressed == KEY_LEFT) {
        desiredPos.x--;
        direction = LEFT;
    } else if(keyPressed == KEY_RIGHT) {
        desiredPos.x++;
        direction = RIGHT;
    } else if(keyPressed == KEY_DOWN) {
        if(isJumping == 0)
            desiredPos.y++;
    }
}

void Entity::setDesiredPosition(point where) {
    desiredPos = where;
}

point Entity::getDesiredPosition(){
    return desiredPos;
}


int Entity::getIsJumping() {
    return isJumping;
}


void Entity::jump() {
    isJumping = 1;
}


int Entity::getDirection() {
    return this->direction;
}


void Entity::animation(bool isMonster) {
    if(!isMonster) {
        //siamo il giocatore, se stiamo saltando va eseguita la animazione
        if(isJumping == 1) {
            if(jumpTicks > 5)
                desiredPos.y--;
            
            if(direction == LEFT)
                desiredPos.x--;
            else if (direction == RIGHT)
                desiredPos.x++;

            jumpTicks--;
        }
        if(jumpTicks <= 0) {
            isJumping = 0;
            jumpTicks = 10;
        }
    } else {
        //eseguo l'animazione del mostro
        if (sprite == '#') {
            if(jumpTicks >=5)
                desiredPos.y--;
            else if(jumpTicks <= 0 && jumpTicks > -5)
                desiredPos.x--;
            else if(jumpTicks <= -5 && jumpTicks > -10)
                desiredPos.x++;
            else if(jumpTicks <= -10)
                jumpTicks = 11;

            jumpTicks--;
        } else if (sprite == '?') {
            if(jumpTicks <= 0 && jumpTicks > -5)
                desiredPos.x--;
            else if(jumpTicks <= -10)
                jumpTicks = 11;

            jumpTicks--;
        } else if (sprite == '&') {
            if(jumpTicks <= 0 && jumpTicks > -5)
                desiredPos.x--;
            else if(jumpTicks <= -5 && jumpTicks > -10)
                desiredPos.x++;
            else if(jumpTicks <= -10)
                jumpTicks = 11;
            jumpTicks--;
        }

        
    }

}