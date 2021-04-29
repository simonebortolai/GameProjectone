#ifndef PRINTER_HPP_INCLUDED
#define PRINTER_HPP_INCLUDED

#include <ncurses.h>
#include "misc.hpp"

// lo scopo di questo insieme di funzioni è quello di stampare

void startDraw();
void endDraw();
void printChar(int x, int y, char ch);
void printString(point pointXY, char* string);
void drawRect(int startX, int startY, int width, int heigth);
void printRoom(char ** cont);
void printEverything(point dim);

#endif