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

void printRoom(char ** cont, int x, int y, int width, int heigth) {
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < width; j++) {
            move(i+y, j+x);
            printw((*(cont+i)+j));
        }
    }
}

void printEverything(char ** room, point dim) {
    startDraw();
    drawRect(0,0, dim.x, dim.y);
    printRoom(room, 0, 0, dim.x, dim.y);
    endDraw();
}


void printEverything(char ch, point dim) {
    startDraw();
    drawRect(0,0, dim.x, dim.y);
    printChar(dim, ch);
    endDraw();
}