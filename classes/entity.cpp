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

char Entity::getSprite() {
    return sprite;
}

point Entity::getPosition(){
    return position;
}


point Entity::getDesiredPosition(){
    //da mettere gli if che modificano la posizione
    return position;
}

const char * Entity::toString() {
    const char * temp = "Sono un entità";
    return temp;
}