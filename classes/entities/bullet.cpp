#include "bullet.hpp"


Bullet::Bullet(point position, char sprite, int speed) : Entity(position, sprite) {
    this->speed = sprite;
}
