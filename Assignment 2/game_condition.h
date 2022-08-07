#ifndef GAME_CONDITION_H
#define GAME_CONDITION_H
#include "linkedlist.h"

int condition(LinkedListNode* currentNode, int winCond, int foodXValue, int foodYValue, int numRow, int numCol, int lowerX, int lowerY, int foodToWin, int foodTally);

#endif