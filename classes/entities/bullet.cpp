#include "bullet.hpp"


Bullet::Bullet(point position, char sprite, int speed, int damage) : Entity(position, sprite) {
    this->speed = speed;
    this->damage = damage;
}


void Bullet::setSpeed(int s){
    speed=s;
}

void Bullet::setDamage(int d){
    damage=d;
}

int Bullet::getSpeed(){
    return speed;
}

int Bullet::getDamage(){
    return damage;
}