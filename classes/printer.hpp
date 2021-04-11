#ifndef PRINTER_HPP_INCLUDED
#define PRINTER_HPP_INCLUDED

#include <ncurses.h>
#include "misc.hpp"

// lo scopo di questa classe è quello di stampare la stanza

void startDraw();
void endDraw();
void printChar(point pointXY, char ch);
void printString(point pointXY, char* string);
void drawRect(int startX, int startY, int width, int heigth);
void printRoom(char ** cont);


#endif