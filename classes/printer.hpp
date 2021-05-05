#ifndef PRINTER_HPP_INCLUDED
#define PRINTER_HPP_INCLUDED

#include <ncurses.h>
#include "misc.hpp"
#include "./entities/livingentity.hpp"

// lo scopo di questo insieme di funzioni è quello di stampare sulla finestra di ncurses

void startDraw();
void endDraw();
void printChar(point point, char ch);
void printString(point point, const char* string);
void drawRect(int startX, int startY, int width, int heigth);
void printRoom(char ** cont, point start, point size);
void printEverything(char ** room, point roomSize, point dim);

#endif