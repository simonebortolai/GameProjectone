#ifndef SPACE2D_HPP_INCLUDED
#define SPACE2D_HPP_INCLUDED

#include "misc.hpp"
#include <stdexcept>
#include <string>

/*
Questa classe serve a gestire uno spazio bidimensionale, permettendomi di accedere ai singoli caratteri e modificarne il contenuto.
Sono costretto a dichiarare content come puntatore a puntatori anche se in realtà il size è fissato e conosciuto durante la compilazione
*/


class Space2d {
    protected:
        point size;
        char ** content;
        void allocateContent();

    public:
        Space2d(point size);
        char ** getContent();
        void setPixel(point p, char a);
        char getPixel(point p);
        
};




#endif