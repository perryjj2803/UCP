#include <stdio.h>
#include <stdlib.h>
#include "play_area.h"
#include "random_generator.h"

/*Dynamically allocated size of play area using malloc*/
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
	
/*Print the play area, printing boundaries first when values of i and j are equal to the boundary co-ordinates, followed by printing each item within the program (snake and food)*/
void printarray(char** playArea, int numRow, int numCol, int foodXValue, int foodYValue, int snakeXValue, int snakeYValue, char headDirection)
{
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
	/*playArea[tailXValue][tailYValue] = '#'; planned on using to print tail values within the playArea array*/
	playArea[snakeXValue][snakeYValue] = headDirection;

	for(i=0; i<numRow; i++)
	{
		for(j=0; j<numCol; j++)
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
	
/*Free memory allocation for playArea array*/
void freeplayArea(char** playArea, int numRow, int numCol)
{
	int i=0;
	for(i=0; i<numRow; i++)
	{
		free(playArea[i]);
	}
	free(playArea);
}
