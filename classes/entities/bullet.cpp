#include "bullet.hpp"
using namespace std;

#define NODIR -1
#define RIGHT 0
#define LEFT 1

Bullet::Bullet(point position, char sprite, int speed, int damage, int direction) : Entity(position, sprite, direction) {
    this->speed = speed;
    this->damage = damage;
}


void Bullet::goForward() {
    point tmp = this->getPosition();
    if(this->direction == LEFT) {
        tmp.x -= this->speed;
        this->setDesiredPosition(tmp);
    } else {
        tmp.x += this->speed;
        this->setDesiredPosition(tmp);
    }
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