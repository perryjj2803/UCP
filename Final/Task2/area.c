#include <stdio.h>
#include <stdlib.h>
#include "area.h"

/*This function creates/mallocs the play area array*/
int** initialarray(int numCol, int numRow)
{
    int i=0;
	int** playArea = (int**)malloc(sizeof(int*)*numCol);
				
	for(i = 0; i < numCol; i++)
	{
		playArea[i] = (int*)malloc(sizeof(int)*numRow);
	}

	return playArea;
}

/*This function prints the play area in colour*/
void printArea(int numRow, int numCol, int** playArea)
{
	int i, j;
	for(i=0; i<numCol; i++)
	{
		for(j=0; j<numRow; j++)
		{
			if(playArea[i][j] == 0)
			{
				printf("\033[0;107m");
			}
			else
			{
				printf("\033[0;100m");
			}
			printf(" ");
			printf("\033[0m");
		}
		printf("\n");
	}
}
/*This function frees the  play area array*/
void freeArea(int** playArea, int numRow, int numCol)
{
	int i=0;
	for(i=0; i<numRow; i++)
	{
		free(playArea[i]);
	}
	free(playArea);
}