#include <stdio.h>
#include <stdlib.h>

int** initialarray(int numRow, int numCol)
{
	int i=0;
	int j=0;
	int** playArea = (int**)malloc(sizeof(int*)*numRow);
	
	for(int i = 0; i < numRow; i++)
	{
		playArea[i] = (int*)malloc(sizeof(int)*numCol);
	}
		for(i=0; i < numRow; i++)
		{
			for(j=0; j < numCol; j++)
			{
				playArea[i][j] = 0;
			}
		}
	}
	return playArea;

}

void printarray(int** playArea, int numRow, int numCol)
{
	int i=0;
	int j=0;
	for(int i=0; i < numRow; i++)
	{
		for(int j=0; j < numCol; j++)
		{
			printf("%d ", playArea[i][j]);
		}
		printf("\n");
	}
	
}

void freeplayArea(int** playArea, int numRow, int numCol)
{
	int i=0;
	for(i = 0; i < numRow; i++)
	{
		free(playArea[i]);
	}
	free(playArea);
}

int main(int argc, char** argv)
{
	int numRow;
	int numCol;
	int snakeSize;
	int initialSnake;
	int ch;
	if(argc != 4)
	{
		perror("Incorrect amount of arguments. Program Usage: ./snake <row_map> <col_map> <snake_length>");
	}
	else
	{
	}
	numRow = atoi(argv[1]);
	numCol = atoi(argv[2]);
	snakeSize = atoi(argv[3]);

	numRow = 4;
	numCol = 3;
	snakeSize = 2;
	int** playArea = initialarray(numRow, numCol);
	
	printarray(playArea, numRow, numCol);
    
	freeplayArea(playArea, numRow, numCol);

	return 0;
}

