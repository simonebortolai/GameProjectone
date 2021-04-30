#include "entity.hpp"


Entity::Entity(char sprite){
    this->sprite = sprite;
}


Entity::Entity(point position, char sprite){
    this->sprite = sprite;
    this->position = position;
}


void Entity::setPosition(point position){
    this->position = position;
}


void Entity::setDesiredPosition(int where) {
    //caterva di if per key up e down
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