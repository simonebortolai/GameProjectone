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
    isJumping = false;
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
    } else if(keyPressed == KEY_DOWN)
        desiredPos.y++;
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
    desiredPos.y--;
    isJumping = true;
}