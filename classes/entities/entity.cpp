#include "entity.hpp"


Entity::Entity(char sprite){
    this->sprite = sprite;
}


Entity::Entity(point position, char sprite){
    this->sprite = sprite;
    this->position = position;
    desiredPos = {0,0};
}


void Entity::setPosition(point position){
    this->position = position;
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