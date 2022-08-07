#ifndef AREA_H
#define AREA_H

int** initialarray(int numCol, int numRow);
void printArea(int numRow, int numCol, int** playArea);
void freeArea(int** playArea, int numRow, int numCol);

#endif