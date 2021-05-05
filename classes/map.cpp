#include "map.hpp"


Map::Map(allEntityList * al, point dim) {
    this->allEntity = al;
    this->boxDim = dim;
    currentRoom = NULL;
    firstRoom = NULL;
    counter = 0;
    addRoomToTail();    //creo la prima stanza
}


void Map::addRoomToTail() {
    pRoomList tmp = firstRoom;

    //creo la nuova stanza
    pRoomList add = new roomList;
    add->value = new Room(boxDim, counter);
    add->next = NULL;


    if(firstRoom != NULL) {
        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = add;
        tmp->next->prev = tmp;
    } else {
        firstRoom = add;
        firstRoom->prev = NULL;
    }
    
    ++counter;
}


/*
questa funzione fa due cose (le quali si possono spezzare in due funzioni volendo):
Prende la posizione di player e
1. aggiunge una stanza se è nell'ultima stanza e supera un punto preciso
2. setta la currentRoom giusta
*/
void Map::checkPlayerPosition() {
    roomPoint playerPos = virtualToReal((*allEntity->player).getDesiredPosition());


    //aggiungi stanza
    if(playerPos.nRoom == counter && playerPos.x > (boxDim.x/4)-1)
        addRoomToTail();
    
    //punto alla stanza corrente
    currentRoom = firstRoom;
    for(int i = 0; i < playerPos.nRoom; i++)
        currentRoom = currentRoom->next;
}


/*
è un modo brutale per muovere tutte le entità ma
dovrebbe funzionare, volendo si può cercare un modo per
muovere solo le entità che si sono mosse, ma in teoria si
muovono tutte quindi è inutile fare una cosa del genere
*/
void Map::moveAllEntities() {
    eraseAllEntities(); //cancella le entità
    writeAllEntities(); //le scrive dove si devono muovere e setta la nuova posizione
}


/*
dopo aver disegnato nelle stanze la posizione dell'entità
setto la posizione dell'entità usando desiredPosition,
inoltre controllo la posizone del giocatore ed eseguo
checkPlayerPosition()
*/
void Map::writeAllEntities() {
    //write player
    roomPoint playerPos = virtualToReal((*allEntity->player).getDesiredPosition());
    writeCharInRoom((*allEntity->player).getSprite(), playerPos);
    (*allEntity->player).setPosition((*allEntity->player).getDesiredPosition());
    checkPlayerPosition();

    //write monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom((*ml->value).getSprite(), virtualToReal((*ml->value).getDesiredPosition()));
        (*ml->value).setPosition((*ml->value).getDesiredPosition());
        ml = ml->next;
    }

    //write bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom((*bl->value).getSprite(), virtualToReal((*bl->value).getDesiredPosition()));
        (*bl->value).setPosition((*bl->value).getDesiredPosition());
        bl = bl->next;
    }
}


//sostituisce al posto delle entità uno spazio
void Map::eraseAllEntities() {
    //erase player
    writeCharInRoom(' ', virtualToReal((*allEntity->player).getPosition()));

    //erase monsters
    monsterList * ml = allEntity->headMonster;
    while(ml != NULL) {
        writeCharInRoom(' ', virtualToReal((*ml->value).getPosition()));
        ml = ml->next;
    }

    //erase bullets
    bulletList * bl = allEntity->headBullet;
    while(bl != NULL) {
        writeCharInRoom(' ', virtualToReal((*bl->value).getPosition()));
        bl = bl->next;
    }
}


roomPoint Map::virtualToReal(point p) {
    int nRoom = p.x/boxDim.x;
    int x = p.x%boxDim.x;
    int y = p.y;
    roomPoint temp {nRoom, x, y};
    return temp;
}




point Map::realToVirtual(roomPoint rPoint) {
    int x = rPoint.nRoom*rPoint.x + rPoint.x;
    int y = rPoint.y;
    point temp {x, y};
    return temp;
}


//controlla nella stanza giusta se il punto è uno spazio
bool Map::isPointAviable(point p) {
    int room = virtualToReal(p).nRoom;                          //trovo la stanza
    point pTemp = {virtualToReal(p).x, virtualToReal(p).y};     //prendo il punto
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i <= room; i++)
        temp = temp->next;

    return temp->value->isEmpty(pTemp);
}


void Map::writeCharInRoom(char ch, roomPoint p) {
    pRoomList temp = firstRoom;

    //ciclo per puntare alla stanza giusta
    for (int i = 0; i < p.nRoom; i++)
        temp = temp->next;

    temp->value->setPixel({p.x,p.y}, ch);
}

/*
FUNZIONE DA CONTROLLARE
ho copiato e incollato la funzione dal progetto
prima modificando solo i nomi delle variabili.
Quello che dovrebbe fare questa funzione è ritornare la
stanza che visualizza il giocatore e ritornarla, così printer la
stampa. Non l'ho ancora provata perché serve l'implementazione
delle stanze.
*/
char ** Map::getVisualizedWindow() {
    int diff = virtualToReal((*allEntity->player).getPosition()).x - ((boxDim.x/4)-1);
    char ** res;
    char ** content;

    if(counter <= 1) {
        content = (*firstRoom->value).getContent();
    } else {
        char ** part1 = (*(currentRoom->value)).getContent();
        char ** part2;
        if (diff > 0) part2 = (*(currentRoom->next->value)).getContent();
        else part2 = (*(currentRoom->prev->value)).getContent();

        //combine the two rooms
        res = new char * [boxDim.y];
        for (int row = 0; row < boxDim.y; row++) {
            *(res+row) = new char [boxDim.x];
            for (int col = 0; col < boxDim.x; col++) {
                if (diff > 0) {
                    if (col < boxDim.x-diff) res[row][col] = part1[row][col+diff];
                    else res[row][col] = part2[row][col-boxDim.x+diff];
                }
                else if (diff < 0) {
                    if (col+diff < 0) res[row][col] = part2[row][col+boxDim.x+diff];
                    else res[row][col] = part1[row][col+diff];
                } 
                else res[row][col] = part1[row][col];
            }
        }
        return res;
    }

    return content;
}


pRoomList Map::getCurrentRoom() {
    return currentRoom;
}


pRoomList Map::getFirstRoom() {
    return firstRoom;
}