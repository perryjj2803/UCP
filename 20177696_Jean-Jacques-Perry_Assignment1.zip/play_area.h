#ifndef PLAYAREA_H
#define PLAYAREA_H

char** initialarray(int numRow, int numCol);
void freeplayArea(char** playArea, int numRow, int numCol);
void printarray(char** playArea, int numRow, int numCol, int foodXValue, int foodYValue, int snakeXValue, int snakeYValue, char headDirection);

#endif
