#ifndef SPACE2D_HPP_INCLUDED
#define SPACE2D_HPP_INCLUDED

#include "misc.hpp"

/*
Questa classe serve a gestire uno spazio bidimensionale, permettendomi di accedere ai singoli caratteri e modificarne il contenuto.
Sono costretto a dichiarare content pointer of pointer anche se in realtà il size è fissato e conosciuto durante la compilazione, C++ non è abbastanza intelligente per capirlo.
*/


class Space2d {
    protected:
        point size;
        char ** content;
        void allocateContent();
        char getPixel(point p);
        void setPixel(point p, char a);

    public:
        Space2d(point size);
        char ** getContent();
        
};




#endif