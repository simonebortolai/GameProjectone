#include <ncurses.h>
#include <iostream>
#include "entity.hpp"

Entity::Entity(char sprite){
    this->sprite=sprite;
}

Entity::Entity(int x, int y, char sprite){
    this->sprite=sprite;
    position->x=x;
    position->y=y;
}

void Entity::setPosition(point position){
    this->position->x=position->x;
    this->position->y=position->y;
}

point Entity::getPosition(){
    return position;
}

point Entity::getDesiredPosition(){
    
}