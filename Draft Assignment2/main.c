#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    LinkedList* list = createLinkedList();
    int ch, snakeXValue, snakeYValue;
    int numRow = 0; 
    int numCol = 0;
    int i = 0;
    char nodeChar;
    
    FILE *f = fopen(argv[1], "r");
    if(f == NULL)
    {
        printf("Error: could not open the file 'snake.txt'\n");
    }
    else
    {
        fscanf(f, "%d %d", &numRow, &numCol);
        for(i=0; i < 8; i++)
        {
            fscanf(f, "%d %d %c", &snakeXValue, &snakeYValue, &nodeChar);
            LinkedListNode* tempNode = createNode(snakeXValue, snakeYValue, nodeChar);
            insertStart(list, tempNode);
            printf("snake co ordinates are %d %d and the character is %c \n", snakeXValue, snakeYValue, nodeChar);
        }
        fclose(f);
        printf("snake play area size %d %d", numRow, numCol);
    }
    freeLinkedList(list);
    return 0;
}

