#include "entity.hpp"
using namespace std;

#define NODIR -1
#define RIGHT 0
#define LEFT 1

Entity::Entity(point position, char sprite){
    this->sprite = sprite;
    this->position = position;
    this->desiredPos = position;
    direction = NODIR;
    jumpTicks = 10;
    isJumping = 0;
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
        if(!isJumping)
            desiredPos.y++;
    }
}

void Entity::setDesiredPosition(point where) {
    desiredPos = where;
}

char Entity::getSprite() {
    return sprite;
}


point Entity::getPosition(){
    return position;
}


point Entity::getDesiredPosition(){
    return desiredPos;
}


void Entity::jump() {
    cout << "ciao" << endl;
    isJumping = 1;
}

void Entity::animation() {
    if(isJumping == 1) {
        
        if(jumpTicks >= 4) {
            desiredPos.y--;
        }

        if(direction == LEFT) {
            desiredPos.x--;
        } else if (direction == RIGHT) {
            desiredPos.x++;
        }

        jumpTicks--;
    }

    if(jumpTicks <= 0) {
        isJumping = 0;
        jumpTicks = 10;
        printf(" %d \n", isJumping);
        timeout(100000);
    }

}