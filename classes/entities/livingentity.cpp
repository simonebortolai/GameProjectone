#include "livingentity.hpp"


LivingEntity::LivingEntity(point dim, char sprite,int life, int strength) : Entity(dim, sprite){
    this->life = life;
    this->strength = strength;
}

void LivingEntity::addLife(int n){
    this->life += n;
}

void LivingEntity::subLife(int n){
    this->life -= n;
}

void LivingEntity::setLife(int life){
    this->life=life;
}

void LivingEntity::setStrength(int strength){
    this->strength=strength;
}

int LivingEntity::getLife(){
    return life;
}

int LivingEntity::getStrength(){
    return strength;
}