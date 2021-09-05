#include "room.hpp"


Room::Room(point size, int level) : Space2d(size) {
    this->level = level;
    generateRoom(level);
}


void Room::generateRoom(int level) {
    point tmp {size.x-1, 0};
    setPixel(tmp, (char)((int)'a' + level));

    platformInfo info;
    info.y = 4;
    info.lastX = -1;
    info.lastLen = -1;
    info.sideSpace = 7;
    info.minLen = 7;
    info.maxLen = 30;
    generateAllPlatform(4, 5, info);
}


bool Room::isEmpty(point p) {
    if (p.x < 0 || p.x >= size.x || p.y < 0 || p.y >= size.y)
        throw std::invalid_argument( "Qualche buon tempone chiede a Room se un pixel fori dallo schermo è voto" );
    else if (getPixel(p) == ' ')
        return true;
    else
        return false; 
}



bool Room::isFloor(point p) {
    if (p.x < 0 || p.x >= size.x || p.y < 0)
        throw std::invalid_argument( "Qualche buon tempone chiede a Room se un pixel fori dallo schermo è voto" );
    else if (p.y >= size.y)
        return true;    
    else if(getPixel(p) == '=')
        return true;
    else
        return false; 
}


void Room::drawPlatform(point start, int len) {
    for (int i = 0; i < len; i++) {
        point tmp {start.x + i, start.y};
        setPixel(tmp, '=');
    }
}





void Room::generatePlatform(platformInfo & info) {
    point start {-1, size.y - info.y};
    bool destra = true;
    int length = random(info.minLen, info.maxLen);

    /* Decide se randomizzare x, o cacciarlo a sinistra o a destra della scorsa piattaforma */
    if (info.lastX == -1)
        /* è la prima piattaforma, posso metterla dove voglio */
        start.x = random(info.sideSpace, size.x - info.sideSpace - length);
    else {
        bool excedLeft = info.lastX - length < info.sideSpace;
        bool excedRight = info.lastX + info.lastLen + length > size.x-info.sideSpace;
        
        /* se eccedesse da destra o sinistra tocca accorciare la lunghezza, prendiamo quella max */
        if (excedLeft && excedRight) {
            int leftFreeSpace = info.lastX - info.sideSpace;
            int rightFreeSpace = size.x - info.sideSpace - info.lastX - info.lastLen;
            length = max(leftFreeSpace, rightFreeSpace);

            /* visto che è cambiata length bisogna ricalcolare queste due var */
            excedLeft = info.lastX - length < info.sideSpace;
            excedRight = info.lastX + info.lastLen + length > size.x-info.sideSpace;
        }

        
        /* sceglie in da che parte far iniziare la piattaforma */
        if (excedLeft) start.x = info.lastX + info.lastLen;
        else if (excedRight) start.x = info.lastX;
        else {
            int choiche = rand() % 2;
            start.x = info.lastX*(1-choiche) + (info.lastX + info.lastLen)*(choiche);    //giochetto matematico
        }

        if (info.lastX == start.x) destra = false;    

        /*
        // lancio errori quando invade sideSpace 
        if ( (start.x - length < info.sideSpace && !destra) || (start.x + length > size.x - info.sideSpace   && destra)) {
            std::string a = "("  + std::to_string(start.x) + ", " + std::to_string(start.y) + ")\ncon length: " + std::to_string(length) + "\nlastX:" + std::to_string(info.lastX) + "    lastLen: " + std::to_string(info.lastLen) + "\ndestra:" + std::to_string(destra) + "\n start.x - length < 7:" + std::to_string(start.x - length < 7) + "\n("  + std::to_string(excedRight) + ", " + std::to_string(excedLeft) + ")\n" ;
            throw std::runtime_error(std::string("Bad platform") + a);
        }
        */
    }

    /* 
    se devo creare la piattaforma a sinistra di start.x allora ricalcolo start.x
        poi disegno la piattaforma 
    */
    if (!destra) start.x = start.x - length;
    drawPlatform(start, length);

    /* cambio i parametri di info per la prossima piattaforma da generare */
    info.lastX = start.x;
    info.lastLen = length;
}


void Room::generateAllPlatform(int n, int y_span, platformInfo & info) {
    for (int i = 0; i < n; i++) {
        generatePlatform(info);
        info.y += y_span;
    }
}

int Room::getLevel() {
    return level;
}


pMonster Room::generateEnemies(pMonster head, point offset) {
     //DEBUG
    point pos {30+offset.x, 7};
    
    pMonster tmp = new monsterList;
    tmp->next=head;

    if(level%10 == 0){
        //generare miniboss
        return head; //temporary
    }
    else{
        int life, strength, points;
        life = 100+level*10;
        strength=10+level*2;
        points = 10 + level*3;
        tmp->value = new LivingEntity(pos, '#', life, strength, points);
    }

    return tmp;
}


pBonus Room::generateBonus(pBonus head, point offset) {
    point pos {4+offset.x, 21};
    pBonus tmp = new bonusList;

    int bonusType = random(1, 4);
    char type = '!';
    if (bonusType == 1) type = 'P';
    else if (bonusType == 2) type = 'V';
    else if (bonusType == 3) type = 'D';

    tmp->value = new Element(pos, type);
    tmp->next = head;
    return tmp; 
}


char Room::getChar(point pos){
    return getPixel(pos);
}