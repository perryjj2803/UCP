#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "play_area.h"
#include "random_generator.h"
#include "terminal.h"
#include "snake_movement.h"
#include "game_condition.h"

int main(int argc, char** argv)
{

 /*If user does not provide the right number of arguments, the program will print perror*/
	if( argc == 4)
	{
		int numRow = atoi(argv[1]) + 2;
		int numCol = atoi(argv[2]) + 2;
		int snakeSize = atoi(argv[3]);
   		int lowerX = 2; /*set lower bound for random number generator Xvalue to prevent food from spawning on top row*/
		int lowerY = 1;
		int foodXValue, foodYValue;
		int snakeXValue = 1; /*initialize snake in top row*/
		int snakeYValue = snakeSize; /*initialize snake in top row with y value being equivalent to head of snake*/
        char headDirection = '>';
		char direction;
		int loop = 0;

		/*if statements for checking appropriate user input value for arguments*/
		if(numRow < 5 || numCol < 5 || snakeSize < 3)
		{
			perror("Please enter an integer value no lower than 5 for <row_map> and <col_map> and an integer value no less than 3 for <snake_length>");
		}
		else if(numCol < snakeSize+2) /*had to +2 to snakeSize variable as +2 was added to numRow and numCol to initialize the playArea array with boundaries*/
		{
			perror("<col_map> cannot be less than <snake_size>");
		}
		else
		{

		/*int* tailXValue = (int*)malloc(sizeof(int)*numCol); inted use for initializing an array of tail X co-ordinates*/
		/*int* tailYValue = (int*)malloc(sizeof(int)*numCol); inted use for initializing an array of tail Y co-ordinatres*/

    	char** playArea;

   		initRandom();

		foodXValue = Random(lowerX, numRow-2);
		foodYValue = Random(lowerY, numCol-2);

		playArea = initialarray(numRow, numCol);
		
		while(loop == 0)
		{
			printarray(playArea, numRow, numCol, foodXValue, foodYValue, snakeXValue, snakeYValue, headDirection);
		
			/*printf("%d%d\n" ,foodXValue ,foodYValue); used for debugging food co-ordinates in print due to segmentation faults and ensuring food does not print on top line where snake is initialized*/
			/*printf("%d%d\n" ,snakeXValue, snakeYValue); used for debugging snake head co-ordinates to ensure it is printing within the play area when segmentation faults were present*/
			/*printf("%d%d\n" ,numRow-2, numCol-2); used for debugging play area size*/
				
			movement(&snakeXValue, &snakeYValue, &headDirection, &direction);
			/*tail_movement(snakeXValue, snakeYValue, tailLength, &tailYValue, &tailXValue); function to handle tail X and Y value translation for each head movement*/
			loop = condition(&snakeXValue, &snakeYValue, loop, numRow, numCol, foodXValue, foodYValue);
			system("clear");
			

		}
		freeplayArea(playArea, numRow, numCol);
		/*free(tailXValue); planned on using this to clear tailXValue pointer memory but snake tail wasnt working*/
		/*free(tailYValue); planned on using this to clear tailYValue pointer memory but snake tail wasnt working*/
		}	
	}
	else
	{
		perror("Incorrect amount of arguments. Program Usage: ./snake <row_map> <col_map> <snake_length>");	
	}
	return 0;
}



/*Attempted logic for a tail to follow the head co-ordinates of the snake in a "reverse" array*/
/*void tail_movement(int snakeXValue, int snakeYValue, int snakeSize, int* tailXValue, int* tailYValue)
{
	tailXValue[0] = snakeXValue; sets first element in tail X value array to head value of X
	tailYValue[0] = snakeYValue; sets first element in tail Y value array to head value of Y
	int nextXVal, nextYVal;
	int i;
	for(i = 1; i < snakeSize; i++)
	{
		nextXVal = tailXValue[i]; assign tailXValue to temp to keep previous X co-ordinate value
		nextYVal = tailYValue[i]; assign tailYValue to temp to keep previous Y co-ordinate value
		tailXValue[i++] = nextXValue;
		tailYValue[i++] = nextYValue;
	}
}*/

