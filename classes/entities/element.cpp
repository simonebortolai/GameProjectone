#include "element.hpp"


Element::Element(point p, char s){
    this->sprite = s;
    this->position = p;
};

char Element::getSprite() {
    return sprite;
}

point Element::getPosition(){
    return position;
}