#include "bullet.hpp"


Bullet::Bullet(point position, char sprite, int speed) : Entity(position, sprite) {
    this->speed = sprite;
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