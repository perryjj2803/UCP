#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "play_area.h"
#include "random_generator.h"
#include "terminal.h"
#include "snake_movement.h"
#include "game_condition.h"

int main(int argc, char *argv[])
{
    LinkedList* list = createLinkedList();
    int snakeXValue, snakeYValue;
    static int foodXValue;
    static int foodYValue;
    int numRow = 0; 
    int numCol = 0;
    int i = 0;
    int winCond = 0;
    char nodeChar;
    int lowerX = 2;
    int lowerY = 1;
    char** playArea;
    int foodToWin;
    
    foodToWin = atoi(argv[2]);

    if(argc == 3 && (2 <= foodToWin))
    {
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
            /*printf("snake play area size %d %d\n", numRow, numCol); used for debugging snake bodypart co ordinates*/ /*used for debugging play area values in file*/

            initRandom();
            foodXValue = Random(lowerX, numRow-2);
		    foodYValue = Random(lowerY, numCol-2);

            playArea = initialarray(numRow, numCol);
        
            while(winCond == 0)
            {
                static int foodTally;
                printf("Food eaten : %d/%d \n", foodTally, foodToWin);
                printarray(playArea, numRow, numCol, foodXValue, foodYValue, list);
                movement(list -> head);
                winCond = condition(list -> head, winCond, foodXValue, foodYValue, numRow, numCol, lowerX, lowerY, foodToWin, foodTally);
                system("clear");
            }
            freeplayArea(playArea, numRow, numCol);
        }
        freeLinkedList(list);
    }
    else
    {
        perror("Incorrect amount of arguments. Please run program with snake.txt file and number for food count to win (food to win must be 2 or greater");
    }
    return 0;
}



