#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include "misc.hpp"
#include "space2d.hpp"


struct platformInfo {
    int y; 
    int lastX;
    int lastLen;
    int sideSpace;
    int minLen; 
    int maxLen;
};



class Room : public Space2d {
    protected:
        int level;
        void generateRoom(int level);

        void generatePlatform(platformInfo & info);
        void generateAllPlatform(int n, int y_span, platformInfo & info);
        void drawPlatform(point start, int len);
        //lista nemici?

    public:
        Room(point size, int level);
        bool isEmpty(point p);
        int getLevel();

};




#endif