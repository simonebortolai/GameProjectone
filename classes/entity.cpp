#include <stdio.h>
#include "entity.hpp"
#include "misc.hpp"


Entity::Entity(char sprite){
    this->sprite = sprite;
}


Entity::Entity(point * position, char sprite){
    this->sprite = sprite;
    position->x = position->x;
    position->y = position->y;
}


void Entity::setPosition(point * position){
    this->position->x=position->x;
    this->position->y=position->y;
}


point * Entity::getPosition(){
    return position;
}


point * Entity::getDesiredPosition(){
    //da mettere gli if che modificano la posizione
    //return null;
}