#include <ncurses.h>
#include <iostream>
#include "entity.hpp"


LivingEntity::LivingEntity(int x, int y, char sprite,int life, int strength):Entity(x,y,sprite){
    this->life=life;
    this->strength=strength;
}