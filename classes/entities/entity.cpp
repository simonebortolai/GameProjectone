#include "entity.hpp"


Entity::Entity(char sprite){
    this->sprite = sprite;
}


Entity::Entity(point position, char sprite){
    this->sprite = sprite;
    this->position = position;
    this->desiredPos = this->position;
}


void Entity::setPosition(point position){
    this->position = position;
}


void Entity::setDesiredPosition(int keyPressed) {
    if (keyPressed == KEY_UP) {
        desiredPos.y--;
        //jump
    }else if(keyPressed == KEY_LEFT) {
        desiredPos.x--;
    }else if(keyPressed == KEY_RIGHT) {
        desiredPos.x++;
    } else if(keyPressed == KEY_DOWN) {
        desiredPos.y++;
        //gravity
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


const char * Entity::toString() {
    const char * temp = "Sono un entità";
    return temp;
}