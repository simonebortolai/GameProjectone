#include <ncurses.h>
#include "printer.hpp"
#include "misc.hpp"

void startDraw() {
    erase();
}

//disegna le tutto in una volta quello che c'è nel buffer
void endDraw() {
    refresh();
}

//disegna un carattere ch in una posizione definita (x,y)
void printChar(int x, int y, char ch) {
    move(y, x);
    printw("%c", ch);
}

//scrive una stringa in una posizione definita (x,y)
void printString(point pointXY, char* string) {

}

//date basi e altezza disegna un rettangolo 
void drawRect(int startX, int startY, int mwidth, int mheigth) {
    for(int y = 0; y < mheigth; y++) {
        for(int x = 0; x < mwidth; x++) {
            if(y == 0 ||  y == (mheigth - 1)) {
                move(startY+y, startX+x);
                printw("-");
            }
            else if(x == (mwidth - 1) || x == 0){
                move(startY+y, startX+x);
                printw("|");
            }
            if((x==0 && y==0)||(x==0 && y==(mheigth-1))||(x==(mwidth-1) && y==0)||(x==(mwidth-1) && y==(mheigth-1))) {
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

void printEverything(point dim) {
    startDraw();
    drawRect(0,0, dim.x, dim.y);
    endDraw();
}