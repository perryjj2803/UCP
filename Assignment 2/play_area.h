#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "linkedlist.h"

char** initialarray(int numRow, int numCol);
void printarray(char** playArea, int numRow, int numCol, int foodXValue, int foodYValue, LinkedList* list);
void freeplayArea(char** playArea, int numRow, int numCol);

#endif
