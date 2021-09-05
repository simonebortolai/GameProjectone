#include "room.hpp"


Room::Room(point size, int level) : Space2d(size) {
    this->level = level;
    generateRoom(level);
}

/* genera il contenuto fisso (nemici e bonus esclusi della stanza) */
void Room::generateRoom(int level) {
    point tmp {size.x-1, 0};
    setPixel(tmp, (char)((int)'a' + level));    //indicatore della stanza

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
    if (p.x < 0 || p.x >= size.x || p.y < 0 || p.y >= size.y) {
        /* cerchiamo di accedere fuori dalla memoria */
    }
    else if (getPixel(p) == ' ')
        return true;
    else
        return false; 
}



bool Room::isFloor(point p) {
    if (p.x < 0 || p.x >= size.x || p.y < 0) {
        /* cerchiamo di accedere fuori dalla memoria, di nuovo */
    }
    else if (p.y >= size.y)
        return true;    
    else if(getPixel(p) == '=')
        return true;
    else
        return false; 
}


/* Scrive nelle varie celle la piattaforma */
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
    point pos {35+offset.x, 7};
    
    pMonster tmp = new monsterList;

    /*
    Tre tipi di mostri: #  &  ?
    ne viene scelto uno casualmente.
    */
    int sel = random(1, 4);
    char skin = '0';
    int life, strength, points;

    if (sel == 1) {
        skin = '#';
        life = 100;
        strength=10;
        points = 10;
    } else if (sel == 2) {
        skin = '&';
        life = 300;
        strength=5;
        points = 20;
    } else if (sel == 3) {
        skin = '?';
        life = 70;
        strength=25;
        points = 15;
    }
    
    //aumentiamo le statistiche in base al livello
    life += level*5;
    strength += level*2;
    points += level*3;

    /* lo aggiungo in testa alla lista dei nemici */
    tmp->value = new LivingEntity(pos, skin, life, strength, points); 
    tmp->next=head;
    return tmp;
}


pBonus Room::generateBonus(pBonus head, point offset) {
    point pos {55+offset.x, 21};
    pBonus tmp = new bonusList;

    /* scelgo casualmente che tipo di bonus generare */
    int bonusType = random(1, 4);
    char type = '!';
    if (bonusType == 1) type = 'P';
    else if (bonusType == 2) type = 'V';
    else if (bonusType == 3) type = 'D';

    /* Lo aggiungo in testa alla lista dei bonus */
    tmp->value = new Element(pos, type);
    tmp->next = head;
    return tmp; 
}


/* ritorna il carattere che c'è in quella posizione */
char Room::getChar(point pos){
    return getPixel(pos);
}