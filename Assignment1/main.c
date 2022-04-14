#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initialarray(int numRow, int numCol)
{
	int i=0;
	int j=0;
	int** playArea = (int**)malloc(sizeof(int*)*numRow);
				
	for(int i = 0; i < numRow; i++)
	{
		playArea[i] = (int*)malloc(sizeof(int)*numCol);
	}
		for(int i=0; i < numRow; i++)
		{
			for(j=0; j < numCol; j++)
			{
				playArea[i][j] = 0;
			}
		}
		return playArea;
}

/*void printarray(int** playArea, int numRow, int numCol)
{
	int i=0;
	int j=0;
	for(int i=0; i< numRow; i++)
	{
		for(int j=0; j<numCol; j++)
		{
			printf("%d ", playArea[i][j]);
		}
		printf("\n");
	}
}*/

void printarray(int** playArea, int numRow, int numCol, int foodXValue, int foodYValue)
{
	int i=0;
	int j=0;
	for(i=0; i<numRow; i++)
	{
		for(j=0; j<numCol; j++)
		{
			if(i==0 || i==numRow-1 || j==0 || j==numCol-1)
			{
				printf("*");
			}
			/*else
			{
				if(i==snakeXValue && j==snakeYValue)
				{
					printf("0");
				}
				*/else if (i == foodXValue && j == foodYValue)
				{
					printf("@");
				}
				else
				printf(" ");
			}
			printf("\n");
		}
	}	

void freeplayArea(int** playArea, int numRow, int numCol)
{
	int i=0;
	for(i=0; i<numRow; i++)
	{
		free(playArea[i]);
	}
	free(playArea);
}

void initRandom()
{
	srand(time(NULL));
}

int Random(int low, int high)
{
	int number = -1;

	if(low <= high)
	{
		number = (rand() % (high-low+1)) + low;
	}

	return number;
}

int main(int argc, char** argv)
{
	int numRow, numCol, snakeSize, ch;
	int foodXValue = Random(1, numCol);
	int foodYValue = Random(1, numRow);

	initRandom();

	if(argc != 4)
	{
		perror("Incorrect amount of arguments. Program Usage: ./snake <row_map> <col_map> <snake_length>");
	}
	else
	{
	}

	numRow = atoi(argv[1]) + 2;
	numCol = atoi(argv[2]) + 2;
	snakeSize = atoi(argv[3]);

	int** playArea = initialarray(numRow, numCol);

	printarray(playArea, numRow, numCol, foodXValue, foodYValue);

	freeplayArea(playArea, numRow, numCol);

	return 0;
}

