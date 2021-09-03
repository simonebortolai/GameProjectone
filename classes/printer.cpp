#include "printer.hpp"


void startDraw() {
    erase();
}

//disegna le tutto in una volta quello che c'è nel buffer
void endDraw() {
    refresh();
}

//disegna un carattere ch in una posizione definita (x,y)
void printChar(point point, char ch) {
    move(point.y, point.x);
    printw("%c", ch);
}

//scrive una stringa in una posizione definita (x,y)
void printString(point point, const char* string) {
    move(point.y, point.x);
    printw("%s", string);
}

//date basi e altezza disegna un rettangolo 
void drawRect(int startX, int startY, int mwidth, int mheigth) {
    for(int y = 0; y <= mheigth; y++) {
        for(int x = 0; x <= mwidth; x++) {
            if(y == 0 ||  y == mheigth) {
                move(startY+y, startX+x);
                printw("-");
            }
            else if(x == mwidth || x == 0){
                move(startY+y, startX+x);
                printw("|");
            }
            if((x==0 && y==0)||(x==0 && y==mheigth)||(x==mwidth && y==0)||(x==mwidth && y==mheigth)) {
                move(startY+y, startX+x);
                printw("+");
            }
        }
    }
}

void printRoom(char ** cont, point start, point size) {
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            move(i+start.y, j+start.x);
            printw((*(cont+i)+j));
        }
    }
}


void printUI(int dim, LivingEntity* player) {
    move(1,dim+1);
    printw("PUNTEGGIO");
    move(1,dim+11);
    printw("%d",(*player).getPoints());
    move(3,dim+1);
    printw("STATISTICHE");
    move(5,dim+1);
    printw("Vita:");
    move(5,dim+11);
    printw("%d",(*player).getLife());
    move(7,dim+1);
    printw("Forza:");
    move(7,dim+11);
    printw("%d",(*player).getStrength());
}


void printEverything(char ** room, point roomSize, point dim, LivingEntity* player) {
    startDraw();
    printRoom(room, {1,1}, roomSize);
    drawRect(0,0, dim.x, dim.y);
    drawRect(dim.x,0,25,15);
    printUI(dim.x,player);
    endDraw();
}