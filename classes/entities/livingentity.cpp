#include "livingentity.hpp"


LivingEntity::LivingEntity(point dim, char sprite,int life, int strength, int points) : Entity(dim, sprite){
    this->life = life;
    this->strength = strength;
    this->points = points;
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


void LivingEntity::setPoints(int points){
    this->points=points;
}


int LivingEntity::getLife(){
    return life;
}


int LivingEntity::getStrength(){
    return strength;
}


int LivingEntity::getPoints(){
    return points;
}