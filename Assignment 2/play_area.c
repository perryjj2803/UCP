#include <stdio.h>
#include <stdlib.h>
#include "play_area.h"
#include "random_generator.h"
#include "linkedlist.h"

/*used to initialze play area array*/
char** initialarray(int numRow, int numCol)
{
    int i=0;
	char** playArea = (char**)malloc(sizeof(char*)*numRow);
				
	for(i = 0; i < numRow; i++)
	{
		playArea[i] = (char*)malloc(sizeof(char)*numCol);
	}

	return playArea;
}

/*function used to print the game*/
void printarray(char** playArea, int numRow, int numCol, int foodXValue, int foodYValue, LinkedList* list)
{
    int snakeX, snakeY;
    char snakeChar;
    int i=0;
    int j=0;

    for(i=0; i < numRow; i++)
    {
        for(j=0; j < numCol; j++)
        {
            playArea[i][j] = ' ';
        }
    }   

    playArea[foodXValue][foodYValue] = '@';

    snakeX = list -> head -> snakeXValue;
    snakeY = list -> head -> snakeYValue;
    snakeChar = list -> head -> nodeChar;

    playArea[snakeY][snakeX] = snakeChar;

    for(i=0; i < numRow; i++)
    {
        for(j=0; j < numCol; j++)
        {
            if(i==0 || i==numRow-1 || j==0 || j==numCol-1)
            {
                printf("*");
            }
            else
            {
                printf("%c", playArea[i][j]);
            }
        }
        printf("\n");
    }
}

/*function used to free memory from the play area*/
void freeplayArea(char** playArea, int numRow, int numCol)
{
	int i=0;
	for(i=0; i<numRow; i++)
	{
		free(playArea[i]);
	}
	free(playArea);
}
