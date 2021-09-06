#include "space2d.hpp"


Space2d::Space2d(point size) {
    this->size = size;
    allocateContent();
}


void Space2d::allocateContent() {

    int height = this->size.y;
    int width = this->size.x;

    /* Inizializzo tutto con ' ' per evitare memoria sporca 
        *(start + n) mi fa accedere alla n-esima riga
        *(*(start + n) + m) mi fa accedere alla m-esima colonna della n-esima riga
    */
    char** start = new char * [height];
    for (int row = 0; row < height; row++) {
        *(start+row) = new char [width];
        for (int col = 0; col < width; col++) {
            *(*(start+row) + col) = ' ';
        }
    }
    
    this->content = start;
}


char ** Space2d::getContent() {
    return this->content;
}


char Space2d::getPixel(point p) {
    int row = p.y;
    int col = p.x;
    if (row >= 0 && row < size.y && col >= 0 && col < size.x) {
        return (*(*(this->content+row)+col));
    } else {
        //qualcuno cerca di leggere fuori dalla mappa
        return 'x';
    }
}


void Space2d::setPixel(point p, char a) {
    int row = p.y;
    int col = p.x;
    if (row >= 0 && row < size.y && col >= 0 && col < size.x) {
        *(*(this->content+row)+col) = a;
    } else {
        //qualcuno cerca di scrivere fuori dalla mappa
    }
}