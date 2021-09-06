#ifndef PRINTER_HPP_INCLUDED
#define PRINTER_HPP_INCLUDED

#include <ncurses.h>
#include "misc.hpp"
#include "entities/livingentity.hpp"

// lo scopo di questo insieme di funzioni è quello di stampare sulla finestra con ncurses

void startDraw();
void endDraw();
void drawRect(int startX, int startY, int width, int heigth);
void printRoom(char ** cont, point start, point size);
void printUI(int dim, LivingEntity* player);
void printEverything(char ** room, point roomSize, point dim, LivingEntity* player);

#endif